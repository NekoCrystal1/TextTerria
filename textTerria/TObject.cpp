#include "TObject.h"

TObject::TObject(const Vector2& size, const Vector2& position, bool is_visiable) :m_Transform(new Transform(size, position)),
m_bIsVisible(is_visiable), can_delete(false)
{
}

TObject::TObject(Transform* transform, bool is_visiable) : m_Transform(transform),m_bIsVisible(is_visiable), can_delete(true)
{
}

TObject::~TObject()
{
	if (m_Transform) {
		delete m_Transform;
		m_Transform = nullptr;
	}
}

const Transform* TObject::get_transform() const
{
	return m_Transform;
}

void TObject::set_visiable(bool is_visiable)
{
	this->m_bIsVisible = is_visiable;
}

void TObject::set_position(const Vector2& pos)
{
	m_Transform->set_position(pos);
}

void TObject::set_position(float x, float y)
{
	m_Transform->set_position(x, y);
}

bool TObject::get_is_can_delete() const
{
	return this->can_delete;
}
