#include "Animation.h"

Animation::Animation(const Vector2& position):position(position),timer(),frames()
{
}

Animation::~Animation()
{
}

Animation::Frame::Frame(COLORREF fillcolor, COLORREF line, bool is_filled, const Vector2& position):
	points(),transform(position),fillcolor(fillcolor),linecolor(line),is_filled(is_filled)
{
}

Animation::Frame::~Frame()
{
}

void Animation::Frame::on_render() const
{
	const Camera& camera = *Camera::instance();
	setlinecolor(linecolor);
	setfillcolor(fillcolor);
	std::vector<POINT> render_points(points);

	//计算渲染的中心坐标：等于将当前坐标相对相机中心移动
	const Vector2& render_centre = camera.get_render_centre(transform.get_centre_position());
	const Vector2& render_size = camera.get_render_size(transform.get_size());
	const Vector2& render_pos = camera.get_render_pos(transform.get_centre_position(), transform.get_size());

	//记录中心点，计算每个点以中心为坐标系的向量，然后延长向量长度为缩放倍数
	Vector2 centre_vec;
	for (POINT& i : render_points) {
		centre_vec = Vector2(i.x, i.y) - render_centre;
		centre_vec.only_multiply_every_element_modify_self(camera.get_vision_scale());
		centre_vec = centre_vec + render_centre.only_multiply_every_element(camera.get_vision_scale());
		i.x = centre_vec.x + render_pos.x;
		i.y = centre_vec.y + render_pos.y;
	}
	switch (is_filled)
	{
	case 0:
		polygon(render_points.data(), render_points.size());
		break;
	case 1:
		fillpolygon(render_points.data(), render_points.size());
		break;
	}
}

void Animation::Frame::on_render_ui() const
{
	std::vector<POINT> render_points(points);
	const Vector2& pos = this->transform.get_position();
	for (POINT& i : render_points) {
		i.x = i.x + pos.x;
		i.y = i.y + pos.y;
	}
	switch (is_filled)
	{
	case 0:
		polygon(render_points.data(), render_points.size());
		break;
	case 1:
		fillpolygon(render_points.data(), render_points.size());
		break;
	}
}

void Animation::Frame::refresh_size()
{
	int max_x = 0, max_y = 0;
	for (POINT i : points) {
		if (max_x < i.x)
			max_x = i.x;
		if (max_y < i.y)
			max_y = i.y;
	}
	this->transform.set_size(max_x,max_y);
}

void Animation::Frame::set_points(const std::vector<POINT>& points)
{
	this->points = points;
	refresh_size();
}

void Animation::Frame::set_position(const Vector2& position)
{
	transform.set_position(position);
}

void Animation::Frame::set_position(float x, float y)
{
	transform.set_position(x, y);
}

const Transform& Animation::Frame::get_transform() const
{
	return transform;
}
