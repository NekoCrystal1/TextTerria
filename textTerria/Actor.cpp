#include "Actor.h"
#include "Character.h"

//任何底层派生类都必须初始化虚基类
Actor::Actor(CollisionBox::CollisionType collision_type, const Vector2& size, const Vector2& position, bool is_visiable)
	: TObject(size, position, is_visiable), CollisionObject(collision_type, this, size, position, is_visiable), MovementObject()
{
}

Actor::~Actor()
{
}

void Actor::on_update()
{
	CollisionObject::on_update();
	MovementObject::on_update();
}

void Actor::set_position(const Vector2& pos)
{
	CollisionObject::set_position(pos);
}

void Actor::set_position(float x, float y)
{
	CollisionObject::set_position(x,y);
}

