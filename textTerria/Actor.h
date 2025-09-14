#pragma once
#include "MovementComponent.h"
#include "StaticCollisionObject.h"
class Actor : public StaticCollisionActor{
public:
	Actor(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Actor();
public:
	MovementComponent* getMovementComponent();
protected:
	MovementComponent* m_pMovementComponent;
};