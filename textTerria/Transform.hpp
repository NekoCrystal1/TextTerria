#pragma once
#include "Vector2.hpp"
class Transform {
public:
	Transform(const Vector2& size = Vector2(), const Vector2& position = Vector2(),
		const Vector2& scale = Vector2(1), const Vector2& anchor = Vector2(), const Vector2& rotation = Vector2());
	Transform(const Transform& transform);
	~Transform();
	Transform& operator= (const Transform& transform);
	Transform& operator+(const Transform& transform);
	const Vector2& get_position()const;
	const Vector2& get_centre_position()const;
	const Vector2& get_size()const;
	const Vector2& get_scale()const;
	void refresh_scaled_size();
	void refresh_centre();
	void set_position(const Vector2& pos);
	void set_position(float x,float y);
	void set_pos_x(float x);
	void set_pos_y(float y);
	void set_centre_position(const Vector2& centre);
	void set_size(const Vector2& size);
	void set_size(float x, float y);
	void set_size_x(float x);
	void set_size_y(float y);
	void set_scale(const Vector2& scale);
	void set_scale(float scale);
private:
	Vector2 position;
	Vector2 size;
	Vector2 scale;
	Vector2 anchor;
	Vector2 rotation;
	Vector2 scaled_size;
	Vector2 centre;
};

Transform::Transform(const Vector2& size, const Vector2& position, const Vector2& scale, const Vector2& anchor, const Vector2& rotation) :
	size(size), position(position), scale(scale), anchor(anchor), rotation(rotation), scaled_size(Vector2(size.x* scale.x, size.y* scale.y)), centre(position + scaled_size * 0.5)
{
}

Transform::Transform(const Transform& transform) :
	position(transform.position), size(transform.size), scale(transform.scale), anchor(transform.anchor), rotation(transform.rotation), scaled_size(transform.scaled_size)
{
}

Transform::~Transform()
{
}

Transform& Transform::operator=(const Transform& transform)
{
	this->position = transform.position;
	this->size = transform.size;
	this->scale = transform.scale;
	this->anchor = transform.anchor;
	this->rotation = transform.rotation;
	this->scaled_size = transform.scaled_size;
	return *this;
}

Transform& Transform::operator+(const Transform& transform)
{
	Transform oAns(*this);
	oAns.set_position(this->position + transform.position);
	oAns.set_scale(this->scale * transform.scale);
	oAns.rotation += transform.rotation;
	return oAns;
}

inline const Vector2& Transform::get_position() const
{
	return position;
}

inline const Vector2& Transform::get_centre_position() const
{
	return centre;
}

inline const Vector2& Transform::get_size() const
{
	return scaled_size;
}

inline const Vector2& Transform::get_scale() const
{
	return scale;
}

inline void Transform::refresh_scaled_size()
{
	scaled_size.x = size.x * scale.x;
	scaled_size.y = size.y * scale.y;
	refresh_centre();
}

inline void Transform::refresh_centre()
{
	centre = position + scaled_size * 0.5f;
}

inline void Transform::set_position(const Vector2& pos)
{
	this->position = pos;
	refresh_centre();
}

inline void Transform::set_position(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	refresh_centre();
}

inline void Transform::set_pos_x(float x)
{
	this->position.x = x;
	refresh_centre();
}

inline void Transform::set_pos_y(float y)
{
	this->position.y = y;
	refresh_centre();
}

inline void Transform::set_centre_position(const Vector2& centre)
{
	this->centre = centre;
	position = centre - scaled_size * 0.5f;
}

inline void Transform::set_size(const Vector2& size)
{
	this->size = size;
	refresh_scaled_size();
}

inline void Transform::set_size(float x, float y)
{
	this->size.x = x;
	this->size.y = y;
	refresh_scaled_size();
}

inline void Transform::set_size_x(float x)
{
	this->size.x = x;
	refresh_scaled_size();
}

inline void Transform::set_size_y(float y)
{
	this->size.y = y;
	refresh_scaled_size();
}

inline void Transform::set_scale(const Vector2& scale)
{
	this->scale = scale;
	refresh_scaled_size();
}

inline void Transform::set_scale(float scale)
{
	this->scale.x = scale;
	this->scale.y = scale;
	refresh_scaled_size();
}

