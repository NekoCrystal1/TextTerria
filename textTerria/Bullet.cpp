#include "Bullet.h"

Bullet::Bullet(Actor* spawn_scource, const Vector2& size, const Vector2& position):
	TObject(size,position,true),Actor(CollisionBox::CollisionType::Dynamic_Collision,size,position),
	damage(0),life_time_timer(),spawn_scource(spawn_scource)
{
	life_time_timer.set_timer_out_func([this]() {
		can_delete = true;
		});
}

Bullet::~Bullet()
{
}

void Bullet::on_update()
{
	life_time_timer.on_update();
	Actor::on_update();
}

void Bullet::on_render() const
{
	if (!m_bIsVisible)
		return;
}

void Bullet::set_position(const Vector2& pos)
{
	Actor::set_position(pos);
}

void Bullet::set_position(float x, float y)
{
	Actor::set_position(x, y);
}

