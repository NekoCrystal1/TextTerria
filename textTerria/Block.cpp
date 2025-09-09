#include "Block.h"

void Block::initial(const Vector2& size, const Vector2& position)
{
	frame->set_points(std::vector<POINT>({ POINT({0,0}),POINT({(int)size.x,0}), POINT({(int)size.x,(int)size.y}) ,POINT({0,(int)size.y}) }));
	frame->set_position(transform->get_position());
	this->transform->set_size(frame->get_transform().get_size());
	this->collision_box->set_collision_shape(CollisionBox::CollisionShape::rectangle);
	this->collision_box->set_collision_src_layer(0x1);
	collision_box->set_collision_func([&]() {
		this->colide_func(collision_box->get_target()->get_parent());
		});
}

//Block::Block(COLORREF linecolor, const Vector2& size, const Vector2& position): TObject(size, position, true),
//	Actor(size,position,true),frame(AnimationManager::instance()->create_frame(linecolor, linecolor, false, position))
//{
//	initial(size, position);
//}

Block::Block(COLORREF fillcolor, COLORREF linecolor, const Vector2& size, const Vector2& position): TObject(size, position, true),
	Actor(CollisionBox::CollisionType::Static_Collision, size, position,true),frame(AnimationManager::instance()->create_frame(fillcolor, linecolor, true, position))
{
	initial(size, position);
}

Block::~Block()
{
}

void Block::on_update()
{
	//CollisionObject::on_update();
}

void Block::on_render() const
{
	if (!is_visiable)
		return;
	frame->on_render();
}

void Block::set_position(const Vector2& position)
{
	Actor::set_position(position);
	frame->set_position(position);
}

void Block::colide_func(MovementObject* target)
{
	const Vector2& target_pos = target->get_transform()->get_position();
	const Vector2& target_size = target->get_transform()->get_size();
	const Vector2& pos = transform->get_position();
	if (target_pos.y + target_size.y >= pos.y && target_pos.y + target_size.y - target->get_velocity().y <= pos.y) {
		target->set_position(target_pos.x, pos.y - target_size.y);
		target->set_velocity_y(0);
	}
}
