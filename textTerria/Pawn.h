#pragma once
#include "StaticCollisionActor.h"
#include "MovementComponent.h"
class Pawn : public StaticCollisionActor
{
public:
	Pawn(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Pawn();
public:
	MovementComponent* getMovementComponent();
protected:
	MovementComponent* m_pMovementComponent;
};