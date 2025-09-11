#pragma once
#include "Actor.h"
#include "CollisionComponent.h"
class StaticCollisionActor : public Actor
{
public:
	StaticCollisionActor(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~StaticCollisionActor();
public:
	CollisionComponent* getCollisionComponent();
protected:
	virtual void colide_func(TEntityObject* target) = 0;
protected:
	CollisionComponent* m_pCollisionComponent;
};