#include "Platform.h"

void Platform::initial(const Vector2& size, const Vector2& position)
{
	//frame->set_points(std::vector<POINT>({ POINT({0,0}),POINT({(int)size.x,0}) ,POINT({(int)size.x,(int)size.y}) ,POINT({0,(int)size.y}) }));
	//frame->set_position(m_Transform->get_position());
	//this->m_Transform->set_size(frame->get_transform().get_size());
	collision_box->set_collision_shape(CollisionBox::CollisionShape::platform_linear);
	//collision_box->set_collision_dst_layer(0x2);
	collision_box->set_collision_src_layer(0x2);
	collision_box->set_collision_func([&]() {
		this->colide_func(collision_box->get_target()->get_parent());
		});
}

//平台默认可见,红色填充,黑色线框,碰撞为线性碰撞
//Platform::Platform(COLORREF linecolor, const Vector2& size, const Vector2& position) : TObject(size, position, true),
//	Dynamic_Actor(size, position, true), frame(AnimationManager::instance()->create_frame(linecolor, linecolor, false, position))
//{
//	//frame->set_points(std::vector<POINT>({ POINT({0,0}),POINT({(int)size.x,0}) ,POINT({(int)size.x,(int)size.y}) ,POINT({0,(int)size.y}) }));
//	//this->transform.set_size(frame->get_transform().get_size());
//	//collision_box->set_collision_shape(CollisionBox::CollisionShape::rectangle);
//	initial(size, position);
//}

Platform::Platform(COLORREF fillcolor, COLORREF linecolor, const Vector2& size, const Vector2& position) : TObject(size, position, true),
	Actor(CollisionBox::CollisionType::Static_Collision, size, position, true)
{
	initial(size, position);
}

Platform::~Platform()
{
}

void Platform::on_update()
{
	//CollisionObject::on_update();
}

void Platform::on_render() const
{
	if (!m_bIsVisible)
		return;
}

void Platform::set_position(const Vector2& position)
{
	Actor::set_position(position);
}

void Platform::set_position(float x, float y)
{
	Actor::set_position(x, y);
}

void Platform::colide_func(MovementObject* target)
{
	const Vector2& target_pos = target->get_transform()->get_position();
	const Vector2& target_size = target->get_transform()->get_size();
	const Vector2& pos = m_Transform->get_position();
	if (target_pos.y + target_size.y >= pos.y && target_pos.y + target_size.y - target->get_velocity().y <= pos.y) {
		target->set_position(target_pos.x, pos.y - target_size.y);
		target->set_velocity_y(0);
	}
}