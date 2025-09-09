#pragma once
#include "Bullet.h"
class Arrow : public Bullet {
public:
	Arrow(Actor* spawn_scource, const Vector2& position = Vector2());
	~Arrow();
	//void on_update() override;
};