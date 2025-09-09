#pragma once
#include "Actor.h"
#include "Timer.h"
class Bullet : public Actor {
public:
	Bullet(Actor* spawn_scource, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Bullet();
	virtual void on_update() override;
	virtual void on_render() const override;
	virtual void set_position(const Vector2& pos)override;
	virtual void set_position(float x, float y)override;
protected:
	float damage;
	Animation::Frame* bullet_frame;
	Timer life_time_timer;
	Actor* spawn_scource;
};