#include "TObject.h"

TObject::TObject(Transform* transform) : m_Transform(transform)
{
}

inline const Transform* TObject::get_transform() const
{
	return m_Transform;
}

inline void TObject::set_position(const Vector2& pos)
{
	m_Transform->set_position(pos);
}

inline void TObject::set_position(float x, float y)
{
	m_Transform->set_position(x, y);
}
