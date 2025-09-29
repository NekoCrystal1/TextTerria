#include "TObject.h"

TObject::TObject(Transform* transform) : m_pLocalTransform(transform)
{
}

const Transform* TObject::getTransform() const
{
	return m_pLocalTransform;
}

const Transform& TObject::getLocalTransform() const
{
	return *m_pLocalTransform;
}

void TObject::setLocalPosition(const Vector2& pos)
{
	this->setLocalPosition(pos.x, pos.y);
}

void TObject::setLocalPosition(float x, float y)
{
	m_pLocalTransform->setOriginPosition(x, y);
}

void TObject::setLocalAnchor(const Vector2& oNewAnchor)
{
	m_pLocalTransform->set_anchor(oNewAnchor);
}
