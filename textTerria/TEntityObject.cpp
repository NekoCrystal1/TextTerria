#include "TEntityObject.h"

TEntityObject::TEntityObject(const Vector2& size, const Vector2& position, TEntityObject* pParent) : TNodeInterface(pParent),
	TWorldTransformObject(size, position),
m_bIsCanBeDeleted(false)
{
}

TEntityObject::TEntityObject(const Transform& transform, TEntityObject* pParent) : TNodeInterface(pParent),
	TWorldTransformObject(transform),
m_bIsCanBeDeleted(false)
{
}

TEntityObject::~TEntityObject()
{
	if (m_pLocalTransform) {
		delete m_pLocalTransform;
		m_pLocalTransform = nullptr;
	}
}

void TEntityObject::on_update()
{
}

void TEntityObject::setCanBeDeleted(bool bValue)
{
	m_bIsCanBeDeleted = bValue;
}

bool TEntityObject::IsCanBeDeleted() const
{
	return m_bIsCanBeDeleted;
}

