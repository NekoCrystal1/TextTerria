#pragma once
#include "Actor.h"
#include "Timer.h"
class Bullet : public Actor {
public:
	Bullet(Actor* spawn_scource, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Bullet();
	virtual void on_update() override;
protected:
	float damage;
	Timer life_time_timer;
	Actor* spawn_scource;
};