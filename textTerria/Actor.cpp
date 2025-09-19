#include "Actor.h"
#include "Character.h"

Actor::Actor(const Vector2& size, const Vector2& position) : StaticCollisionObject(size, position),
m_pMovementComponent(new MovementComponent(this))
{
}

Actor::~Actor()
{
    delete m_pMovementComponent;
}

void Actor::on_update()
{
    m_pMovementComponent->on_update();
    StaticCollisionObject::on_update();
}

MovementComponent* Actor::getMovementComponent()
{
    return m_pMovementComponent;
}
