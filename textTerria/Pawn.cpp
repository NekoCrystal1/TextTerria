#include "Pawn.h"

Pawn::Pawn(const Vector2& size, const Vector2& position) : StaticCollisionActor(size, position),
m_pMovementComponent(new MovementComponent(this))
{
}

Pawn::~Pawn()
{
	delete m_pMovementComponent;
}

MovementComponent* Pawn::getMovementComponent()
{
	return m_pMovementComponent;
}
