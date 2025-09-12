#include "TEntityObject.h"

TEntityObject::TEntityObject(const Vector2& size, const Vector2& position) : TObject(new Transform(size, position)),
m_bIsCanBeDeleted(false)
{
}

TEntityObject::TEntityObject(const Transform& transform) : TObject(new Transform(transform)),
m_bIsCanBeDeleted(false)
{
}

TEntityObject::~TEntityObject()
{
	if (m_pTransform) {
		delete m_pTransform;
		m_pTransform = nullptr;
	}
}

void TEntityObject::setCanBeDeleted(bool bValue)
{
	m_bIsCanBeDeleted = bValue;
}

bool TEntityObject::IsCanBeDeleted() const
{
	return m_bIsCanBeDeleted;
}
