#include "CollisionObject.h"
CollisionObject::CollisionObject(CollisionBox::CollisionType collision_type, Actor* p,
	const Vector2& size, const Vector2& position, bool is_visiable) :
	TObject(size, position,is_visiable),collision_box(CollisionManager::instance()->create_collision_box(collision_type, p, m_Transform))
{
}

CollisionObject::~CollisionObject()
{
	CollisionManager::instance()->remove_box(this->collision_box);
}

void CollisionObject::on_update()
{
	//碰撞箱更新在碰撞管理器中处理
	//collision_box->on_update();
	return;
}

void CollisionObject::set_position(const Vector2& position)
{
	collision_box->set_position(position);
	m_Transform->set_position(collision_box->get_position());
}

void CollisionObject::set_position(float x, float y)
{
	collision_box->set_position(x, y);
	m_Transform->set_position(collision_box->get_position());
}

void CollisionObject::set_collision_src_layer(unsigned int src_layer)
{
	collision_box->set_collision_src_layer(src_layer);
}

void CollisionObject::set_collision_dst_layer(unsigned int dst_layer)
{
	collision_box->set_collision_dst_layer(dst_layer);
}

void CollisionObject::set_collision_layer(unsigned int src_layer, unsigned int dst_layer)
{
	collision_box->set_collision_layer(src_layer, dst_layer);
}

CollisionBox* CollisionObject::get_collision_box()
{
	return collision_box;
}

void CollisionObject::set_collision_shape(CollisionBox::CollisionShape shape)
{
	collision_box->set_collision_shape(shape);
}

void CollisionObject::set_collision_func(std::function<void()> on_collision)
{
	collision_box->set_collision_func(on_collision);
}
