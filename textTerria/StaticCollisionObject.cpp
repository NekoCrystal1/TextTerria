#include "StaticCollisionObject.h"

StaticCollisionActor::StaticCollisionActor(const Vector2& size, const Vector2& position) : TEntityObject(size, position),
m_pCollisionComponent(new CollisionComponent(this))
{
}

StaticCollisionActor::~StaticCollisionActor()
{
	delete m_pCollisionComponent;
}

CollisionComponent* StaticCollisionActor::getCollisionComponent()
{
	return m_pCollisionComponent;
}

void StaticCollisionActor::colide_func(TEntityObject* target)
{
}
