#pragma once
#include "StaticCollisionObject.h"
#include "Animation.h"
class Platform : public StaticCollisionObject 
{
public:
	Platform(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Platform();
public:
	virtual bool initial() override;
protected:
	virtual void colide_func(TEntityObject* target);
protected:
	Animation* m_pPlatformAnimation;
};