#include "Arrow.h"
#include "CollisionManager.h"
Arrow::Arrow(Actor* spawn_scource,const Vector2& position) : TObject(Vector2(48, 27), position, true),
Bullet(spawn_scource, Vector2(48,27),position)
{
	this->set_velocity_x(20);
	this->set_fx(0);
	this->set_gravity(0.1);
	this->life_time_timer.set_end_time(120);
}

Arrow::~Arrow()
{
}
