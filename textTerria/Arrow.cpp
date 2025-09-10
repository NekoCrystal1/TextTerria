#include "Arrow.h"
#include "CollisionManager.h"
Arrow::Arrow(Actor* spawn_scource,const Vector2& position) : Bullet(spawn_scource, Vector2(48,27),position)
{
	m_pMovementComponent->set_velocity_x(20);
	m_pMovementComponent->set_fx(0);
	m_pMovementComponent->set_gravity(0.1);
	this->life_time_timer.set_end_time(120);
}

Arrow::~Arrow()
{
}
