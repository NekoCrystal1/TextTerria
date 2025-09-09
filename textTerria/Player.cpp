#include "Player.h"
#include "InputManager.h"
#include "ItemManager.h"
Player::Player(const Vector2& size, const Vector2& position) : TObject(size, position, true), Character(size, position, is_visiable),
bag_pack(ItemManager::instance()->create_storage(this, 45)), main_hand_slot_id(0)
{
	player_frame = AnimationManager::instance()->create_frame(0xAA88AA, 0xFF2200, true,transform->get_position());
	//Íæ¼Ò´óÐ¡30*80
	player_frame->set_points(std::vector<POINT>({
		{15,0},{30,13},{30,40},{20,40},{20,70},{30,70},{30,80},{0,80},{0,70},{10,70},{10,40},{0,40},{0,13}
		}));
	collision_box->set_collision_shape(CollisionBox::CollisionShape::rectangle);
	collision_box->set_collision_dst_layer(0x3);
	collision_box->set_collision_src_layer(0x3);
	//collision_box->set_visiable();
	collision_box->set_collision_func([&]() {
		switch (this->get_collision_box()->get_collision_src_layer() & this->get_collision_box()->get_target()->get_collision_dst_layer())
		{
		default:
			break;
		}
		});
	bag_pack->modify_in(0, ItemManager::instance()->create_Item(bag_pack,1));
}

Player::~Player()
{
}

void Player::on_update()
{
	InputManager* input = InputManager::instance();
	Vector2 move_velocity;
	
	if ((input->is_key_down('A') && input->is_key_down('D')) || input->is_key_up('A') || input->is_key_up('D'))
		this->acceleration.x = 0;
	else if (input->is_key_down('A'))
		this->acceleration.x = -10;
	else if (input->is_key_down('D'))
		this->acceleration.x = 10;

	if (input->is_key_down(VK_SPACE))
		if(input->is_key_down('S'))
			this->collision_box->set_collision_dst_layer(collision_box->get_collision_dst_layer() & 0xFFFFFFFD);
		else if (input->is_key_down(VK_SPACE) && this->velocity.y == 0 && !is_free_fall_heighest_y)
			this->velocity.y -= 22;
	if (input->is_key_up('S') || input->is_key_up(VK_SPACE))
		this->collision_box->set_collision_dst_layer(collision_box->get_collision_dst_layer() | 0x2);

	Actor::on_update();
}

void Player::on_render() const
{
	if (!is_visiable)
		return;
	player_frame->on_render();
	collision_box->on_render();
}

void Player::set_position(const Vector2& pos)
{
	Actor::set_position(pos);
	player_frame->set_position(pos);
}

void Player::set_position(float x, float y)
{
	Actor::set_position(x, y);
	player_frame->set_position(x, y);
}

Storage* Player::get_storage() const
{
	return this->bag_pack;
}

