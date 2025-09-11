#include "Actor.h"
#include "Character.h"

Actor::Actor(const Vector2& size, const Vector2& position) : TEntityObject(size, position),
m_pAnimation(nullptr)
{
}

Actor::~Actor()
{
}
