#pragma once
#include <string>
#include <unordered_map>
#include "TEntityObject.h"
#include "AnimationManager.h"
class Actor : public TEntityObject{
public:
	Actor(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Actor();
protected:
	Animation* m_pAnimation;
};