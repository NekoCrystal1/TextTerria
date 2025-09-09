#pragma once
#include <easyx.h>
#include "Transform.h"
#include "Singleton.hpp"
class Camera : public Singleton<Camera>
{
	friend Singleton<Camera>;
public:
	void on_input(ExMessage& msg);
	void on_uodate();
	const Transform& get_transform()const;
	const Vector2& get_centre()const;
	const Vector2& get_position()const;
	const Vector2& get_vision_scale()const;
	Vector2 get_render_centre(const Vector2& centre_position)const;
	Vector2 get_render_size(const Vector2& size)const;
	Vector2 get_render_pos(const Transform& target_transform)const;
	Vector2 get_render_pos(const Vector2& centre_position, const Vector2& size)const;
	void set_centre_position(const Vector2& centre_position);
	void set_position(const Vector2& position);
private:
	Camera();
	~Camera() = default;
private:
	Transform transform;
	bool up = 0, down = 0, left = 0, right = 0,add_scale = 0,sub_scale = 0;
	Vector2 vision_scale;
};
static Camera* CAMERA = Camera::instance();