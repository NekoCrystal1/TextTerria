#include "TObject.h"

TObject::TObject(const Vector2& size, const Vector2& position, bool is_visiable) :transform(new Transform(size, position)),
is_visiable(is_visiable), can_delete(false)
{
}

TObject::TObject(Transform* transform, bool is_visiable) : transform(transform),is_visiable(is_visiable), can_delete(true)
{
}

TObject::~TObject()
{
	if (transform) {
		delete transform;
		transform = nullptr;
	}
}

const Transform* TObject::get_transform() const
{
	return transform;
}

void TObject::set_visiable(bool is_visiable)
{
	this->is_visiable = is_visiable;
}

void TObject::set_position(const Vector2& pos)
{
	transform->set_position(pos);
}

void TObject::set_position(float x, float y)
{
	transform->set_position(x, y);
}

bool TObject::get_is_can_delete() const
{
	return this->can_delete;
}
