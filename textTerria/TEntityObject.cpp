#include "TEntityObject.h"

TEntityObject::TEntityObject(const Vector2& size, const Vector2& position) : TObject(new Transform(size, Vector2())),
m_bIsCanBeDeleted(false), m_bIsTransformDirty(false), m_pWorldTransform(new Transform(Vector2(), position))
{
}

TEntityObject::TEntityObject(const Transform& transform) : TObject(new Transform(transform.get_size(), Vector2())),
m_bIsCanBeDeleted(false), m_bIsTransformDirty(false), m_pWorldTransform(new Transform(Vector2(), transform.get_position()))
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

const Transform& TEntityObject::getWorldTransform()
{
	if (m_bIsTransformDirty)
		updateTransform();
	return *m_pWorldTransform;
}

void TEntityObject::updateTransform()
{
	*m_pWorldTransform = *m_pLocalTransform + m_pParentNode->getWorldTransform();
}

void TEntityObject::makeDirty()
{
	m_bIsTransformDirty = true;
	for (TEntityObject* node : m_vecNextNodes)
	{
		node->makeDirty();
	}
}
