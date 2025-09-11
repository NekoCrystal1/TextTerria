#pragma once
#include "StaticCollisionActor.h"
class Platform : public StaticCollisionActor 
{
public:
	Platform(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Platform();
	virtual void on_update();
	virtual void set_position(const Vector2& position) override;
	virtual void set_position(float x, float y) override;
protected:
	virtual void colide_func(TEntityObject* target);
	void initial(const Vector2& size, const Vector2& position);
	
};