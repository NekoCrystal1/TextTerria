#include "Camera.h"

Camera::Camera():transform(Vector2(getwidth(), getheight()), Vector2()), vision_scale(1.0f)
{
}

void Camera::on_input(ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case VK_UP:
			up = true;
			break;
		case VK_DOWN:
			down = true;
			break;
		case VK_LEFT:
			left = true;
			break;
		case VK_RIGHT:
			right = true;
			break;
		case VK_ADD:
			add_scale = true;
			break;
		case VK_SUBTRACT:
			sub_scale = true;
			break;
		}
		break;
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case VK_UP:
			up = false;
			break;
		case VK_DOWN:
			down = false;
			break;
		case VK_LEFT:
			left = false;
			break;
		case VK_RIGHT:
			right = false;
			break;
		case VK_ADD:
			add_scale = false;
			break;
		case VK_SUBTRACT:
			sub_scale = false;
			break;
		}
		break;
	}
}

void Camera::on_uodate()
{
	Vector2 add_pos;
	if (up)
		add_pos.y -= 10;
	if (down)
		add_pos.y += 10;
	if (left)
		add_pos.x -= 10;
	if (right)
		add_pos.x += 10;
	transform.set_position(transform.get_position() + add_pos);
	float modify_sclae = add_scale- sub_scale;
	vision_scale = vision_scale + Vector2(0.02, 0.02) * modify_sclae;
}

const Transform& Camera::get_transform() const
{
	return transform;	
}

const Vector2& Camera::get_centre() const
{
	return transform.get_centre_position();
}

const Vector2& Camera::get_position()const
{
	return transform.get_position();
}

const Vector2& Camera::get_vision_scale() const
{
	return vision_scale;
}

Vector2 Camera::get_render_centre(const Vector2& centre_position) const
{
	//渲染中心 = ( 对象中心 - 相机中心 )  * 缩放 + 相机中心  -> 先求向量，再缩放向量，再还原世界坐标
	return (centre_position - transform.get_centre_position()).only_multiply_every_element(vision_scale) + transform.get_centre_position();
}

Vector2 Camera::get_render_size(const Vector2& size) const
{
	return size.only_multiply_every_element(vision_scale);
}

Vector2 Camera::get_render_pos(const Transform& target_transform) const
{
	//渲染位置 = 渲染中心 - ( 渲染大小 ) / 2
	return ((target_transform.get_centre_position() - transform.get_centre_position()).only_multiply_every_element(vision_scale) + transform.get_centre_position())
		- (target_transform.get_size().only_multiply_every_element(vision_scale)) * 0.5f 
		- transform.get_position();
}

Vector2 Camera::get_render_pos(const Vector2& centre_position, const Vector2& size) const
{
	return ((centre_position - transform.get_centre_position()).only_multiply_every_element(vision_scale) + transform.get_centre_position())
		- (size.only_multiply_every_element(vision_scale)) * 0.5f
		- transform.get_position();
}

void Camera::set_centre_position(const Vector2& centre_position)
{
	transform.set_centre_position(centre_position);
}

void Camera::set_position(const Vector2& position)
{
	transform.set_position(position);
}
