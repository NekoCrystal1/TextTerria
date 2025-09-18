#include "StaticCollisionObject.h"
#include "TLevelManager.h"
StaticCollisionObject::StaticCollisionObject(const Vector2& size, const Vector2& position) : TEntityObject(size, position),
m_pCollisionComponent(new CollisionComponent(this)), m_pAnimation(nullptr)
{
}

StaticCollisionObject::~StaticCollisionObject()
{
	delete m_pCollisionComponent;
	m_pCollisionComponent = nullptr;
}

CollisionComponent* StaticCollisionObject::getCollisionComponent()
{
	return m_pCollisionComponent;
}

bool StaticCollisionObject::initial()
{
	return false;
}

void StaticCollisionObject::colide_func(TEntityObject* target)
{
}
