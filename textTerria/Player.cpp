#include "Player.h"
#include "InputManager.h"
#include "ItemManager.h"
Player::Player(const Vector2& position) : Character(PLAYER_SIZE, position),
bag_pack(ItemManager::instance()->create_storage(this, 45)), main_hand_slot_id(0), m_pPlayerAnimation(nullptr)
{
	bag_pack->modify_in(0, ItemManager::instance()->create_Item(bag_pack,ItemId::ITEM_TEST_BOW));
}

Player::~Player()
{
}

bool Player::initial()
{
	CollisionBox* collision_box = CollisionManager::instance()->create_collision_box(
		CollisionBox::CollisionType::Dynamic_Collision, m_pCollisionComponent);
	if (!collision_box)
	{
		return false;
	}
	m_pCollisionComponent->addCollisionBox("PlayerBody", collision_box);
	collision_box->set_collision_shape(CollisionBox::CollisionShape::SHAPE_RECTANGLE);
	collision_box->set_collision_dst_layer(0x3);
	collision_box->set_collision_src_layer(0x3);
	return true;
}

void Player::on_update()
{
	InputManager* input = InputManager::instance();
	Vector2 move_velocity;
	
	if ((input->is_key_down('A') && input->is_key_down('D')) || input->is_key_up('A') || input->is_key_up('D'))
		m_pMovementComponent->setAcceleration_x(0);
	else if (input->is_key_down('A'))
		m_pMovementComponent->setAcceleration_x(-10);
	else if (input->is_key_down('D'))
		m_pMovementComponent->setAcceleration_x(10);

	CollisionBox* collision_box = m_pCollisionComponent->get_collision_box("PlayerBody");
	if (input->is_key_down(VK_SPACE))
		if(input->is_key_down('S'))
			collision_box->set_collision_dst_layer(collision_box->get_collision_dst_layer() & 0xFFFFFFFD);
		else if (input->is_key_down(VK_SPACE) && m_pMovementComponent->getAcceleration_y() == 0 && !m_pMovementComponent->getIsFreeFallHeighest())
			m_pMovementComponent->setAcceleration_y(22);
	if (input->is_key_up('S') || input->is_key_up(VK_SPACE))
		collision_box->set_collision_dst_layer(collision_box->get_collision_dst_layer() | 0x2);

	Actor::on_update();
}

void Player::setLocalPosition(const Vector2& pos)
{
	Actor::setLocalPosition(pos);
}

void Player::setLocalPosition(float x, float y)
{
	Actor::setLocalPosition(x, y);
}

Storage* Player::get_storage() const
{
	return this->bag_pack;
}

