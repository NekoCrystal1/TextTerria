#pragma once
#include "Actor.h"
class Character : public Actor{
public:
	Character(const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool is_visiable = true);
	~Character();
private:

};