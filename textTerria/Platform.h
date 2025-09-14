#pragma once
#include "StaticCollisionObject.h"
class Platform : public StaticCollisionActor 
{
public:
	Platform(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Platform();
protected:
	virtual void colide_func(TEntityObject* target);
	void initial(const Vector2& size, const Vector2& position);
	
};