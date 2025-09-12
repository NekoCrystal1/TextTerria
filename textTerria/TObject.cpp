#include "TObject.h"

TObject::TObject(Transform* transform) : m_pTransform(transform)
{
}

inline const Transform* TObject::getTransform() const
{
	return m_pTransform;
}

inline void TObject::set_position(const Vector2& pos)
{
	m_pTransform->set_position(pos);
}

inline void TObject::set_position(float x, float y)
{
	m_pTransform->set_position(x, y);
}
