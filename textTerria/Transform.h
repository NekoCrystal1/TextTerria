#pragma once
#include "Vector2.h"
class Transform {
public:
	Transform(const Vector2& size = Vector2(), const Vector2& position = Vector2(),
		const Vector2& scale = Vector2(1), const Vector2& anchor = Vector2(), const Vector2& rotation = Vector2());
	Transform(const Transform& transform);
	~Transform();
	Transform& operator= (const Transform& transform);
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