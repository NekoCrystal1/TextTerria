#pragma once
#include "Pawn.h"
class Character : public Pawn{
public:
	Character(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Character();
protected:
};