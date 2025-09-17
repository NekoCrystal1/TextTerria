#include "TObject.h"

TObject::TObject(Transform* transform) : m_pLocalTransform(transform)
{
}

inline const Transform* TObject::getTransform() const
{
	return m_pLocalTransform;
}

const Transform& TObject::gerLocalTransform() const
{
	return *m_pLocalTransform;
}

inline void TObject::setLocalPosition(const Vector2& pos)
{
	m_pLocalTransform->set_position(pos);
}

inline void TObject::setLocalPosition(float x, float y)
{
	m_pLocalTransform->set_position(x, y);
}
