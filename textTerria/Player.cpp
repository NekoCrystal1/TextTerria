#include "Player.h"
#include "InputManager.h"
#include "ItemManager.h"
Player::Player(const Vector2& size, const Vector2& position) : Character(size, position),
bag_pack(ItemManager::instance()->create_storage(this, 45)), main_hand_slot_id(0)
{
	m_pCollisionComponent->addCollisionBox("PlayerBody", CollisionManager::instance()->create_collision_box(
		CollisionBox::CollisionType::Static_Collision, m_pCollisionComponent));
	CollisionBox* collision_box = m_pCollisionComponent->get_collision_box("PlayerBody");
	collision_box->set_collision_shape(CollisionBox::CollisionShape::SHAPE_RECTANGLE);
	collision_box->set_collision_dst_layer(0x3);
	collision_box->set_collision_src_layer(0x3);
	//collision_box->set_visiable();
	//collision_box->set_collision_func([&]() {
		//switch (this->get_collision_box()->get_collision_src_layer() & this->get_collision_box()->get_target()->get_collision_dst_layer())
		//{
		//default:
		//	break;
		//}
		//});
	bag_pack->modify_in(0, ItemManager::instance()->create_Item(bag_pack,ItemId::ITEM_TEST_BOW));
}

Player::~Player()
{
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

void Player::set_position(const Vector2& pos)
{
	Actor::set_position(pos);
}

void Player::set_position(float x, float y)
{
	Actor::set_position(x, y);
}

Storage* Player::get_storage() const
{
	return this->bag_pack;
}

