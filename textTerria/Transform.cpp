#include "Transform.h"

Transform::Transform(const Vector2& size, const Vector2& position, const Vector2& scale, const Vector2& rotation) :
	rotation(0), size(size), position(position), scale(scale),
	scaled_size(Vector2(size.x* scale.x, size.y* scale.y)), centre(position + scaled_size * 0.5)
{
}

Transform::Transform(const Transform& transform):
	rotation(0), position(transform.position),size(transform.size),scale(transform.scale),scaled_size(transform.scaled_size)
{
}

Transform::~Transform()
{
}

Transform& Transform::operator+=(const Transform& transform)
{
	this->set_position(this->position + transform.position);
	this->set_scale(this->scale * transform.scale);
	this->rotation = this->rotation + transform.rotation;
	return *this;
}

Transform& Transform::operator=(const Transform& transform)
{
	this->position = transform.position;
	this->size = transform.size;
	this->scale = transform.scale;
	this->anchor = transform.anchor;
	this->rotation = transform.rotation;
	this->scaled_size = transform.scaled_size;
	this->centre = transform.centre;
	return *this;
}

Transform Transform::operator+(const Transform& transform) const
{ 
	Transform oAns(*this);
	oAns.set_position(this->position + transform.position);
	oAns.set_scale(this->scale.only_multiply_every_element(transform.scale));
	oAns.rotation = this->rotation + transform.rotation;
	return oAns;
}

Transform Transform::operator-(const Transform& transform) const
{
	Transform oAns(*this);
	oAns.set_position(this->position - transform.position);
	oAns.set_scale(this->scale / transform.scale);
	oAns.rotation = this->rotation - transform.rotation;
	return oAns;
}

Transform Transform::operator*(float fVal)
{
	Transform oAns(*this);
	oAns.set_position(oAns.position * fVal);
	oAns.set_scale(oAns.scale * fVal);
	return oAns;
}

Vector2 Transform::get_position() const
{
	return position + anchor;
}

Vector2 Transform::get_centre_position() const
{
	return centre + anchor / 2;
}

const Vector2& Transform::get_anchor() const
{
	return anchor;
}

const Vector2& Transform::get_size() const
{
	return scaled_size;
}

const Vector2& Transform::get_scale() const
{
	return scale;
}

float Transform::getRotation() const
{
	return rotation;
}

void Transform::refresh_scaled_size()
{
	scaled_size.x = size.x * scale.x;
	scaled_size.y = size.y * scale.y;
	refresh_centre();
}

void Transform::refresh_centre()
{
	centre = position + scaled_size * 0.5f - anchor / 2;
}

void Transform::set_anchor(const Vector2& oNewAcnhor)
{
	anchor = oNewAcnhor;
}

void Transform::set_position(const Vector2& pos)
{
	this->position = pos - anchor;
	refresh_centre();
}

void Transform::set_position(float x, float y)
{
	this->position.x = x - anchor.x;
	this->position.y = y - anchor.y;
	refresh_centre();
}

void Transform::set_pos_x(float x)
{
	this->position.x = x - anchor.x;
	refresh_centre();
}

void Transform::set_pos_y(float y)
{
	this->position.y = y - anchor.y;
	refresh_centre();
}

void Transform::set_centre_position(const Vector2& centre)
{
	this->centre = centre - anchor / 2;
	position = centre - scaled_size * 0.5f - anchor;
}

void Transform::set_size(const Vector2& size)
{
	this->size = size;
	refresh_scaled_size();
}

void Transform::set_size(float x, float y)
{
	this->size.x = x;
	this->size.y = y;
	refresh_scaled_size();
}

void Transform::set_size_x(float x)
{
	this->size.x = x;
	refresh_scaled_size();
}

void Transform::set_size_y(float y)
{
	this->size.y = y;
	refresh_scaled_size();
}

void Transform::set_scale(const Vector2& scale)
{
	this->scale = scale;
	refresh_scaled_size();
}

void Transform::set_scale(float scale)
{
	this->scale.x = scale;
	this->scale.y = scale;
	refresh_scaled_size();
}

void Transform::set_rotation(float rotation)
{
	this->rotation = rotation;
}

void Transform::makeTransformTo(const Transform& transform, float fPerscentage)
{
	Transform subTransform = transform - *this;
	this->set_position(this->position + subTransform.position * fPerscentage);
	this->rotation = this->rotation + subTransform.rotation * fPerscentage;
	if (subTransform.scale.x == 1)
	{
	}
	else if (subTransform.scale.x > 1)
	{
		subTransform.scale.x = 1 + fPerscentage;
	}
	else
	{
		subTransform.scale.x = 1 - fPerscentage;
	}
	if (subTransform.scale.y == 1)
	{
	}
	else if (subTransform.scale.y > 1)
	{
		subTransform.scale.y = 1 + fPerscentage;
	}
	else
	{
		subTransform.scale.y = 1 - fPerscentage;
	}
	this->set_scale(this->scale.only_multiply_every_element(subTransform.scale));
}

