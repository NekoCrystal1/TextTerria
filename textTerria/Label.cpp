#include "Label.h"
#include "UTIL.hpp"
#include "InputManager.h"
Label::Label(Widget* parent, const Vector2& position, const Vector2& size, bool is_handle_scale):
	Widget(parent,position, size), text(), text_original_color((COLORREF)0xFFFFFF), text_render_color((COLORREF)0xFFFFFF), text_handle_color((COLORREF)0x00FFFF), text_height(30),
	text_original_height(text_height), original_transform(*transform), change_scale(1.5),is_handle_scale(is_handle_scale)
{
}

Label::~Label()
{
}

void Label::on_update()
{
	const ExMessage& msg = InputManager::instance()->get_mouse_msg();
	if (is_handle_scale && msg.message == WM_MOUSEMOVE)
		if (check_point_in_rectangle(Vector2(msg.x, msg.y), original_transform)) {
			text_render_color = text_handle_color;
			this->transform->set_scale(change_scale);
			this->transform->set_position(this->original_transform.get_position() - Vector2(
				this->transform->get_size().x / 2 - this->original_transform.get_size().x / 2, this->transform->get_size().y / 2 - this->original_transform.get_size().y / 2));
			text_height = text_original_height * change_scale.x;
		}
		else {
			if (!check_point_in_rectangle(Vector2(msg.x, msg.y), *transform)) {
				text_render_color = text_original_color;
				*this->transform = original_transform;
				text_height = text_original_height;
			}
		}
}

void Label::on_render() const
{
	if (!is_visiable)
		return;
	Widget::on_render();
	//渲染按钮文本
	settextcolor(text_render_color);
	settextstyle(text_height, 0, _T("宋体"));
	outtextxy(this->transform->get_position().x, this->transform->get_position().y + (this->transform->get_size().y - text_height) / 2, _tcsdup(text.c_str()));
}

void Label::refresh_transform()
{
	settextstyle(text_height, 0, _T("宋体"));
	this->transform->set_size_x(textwidth(_tcsdup(text.c_str())) / (transform->get_scale().x ? transform->get_scale().x : 1));
	if (transform->get_size().y < text_height)
		this->transform->set_size_y(text_height);
	this->original_transform = *this->transform;
}

void Label::set_text(const std::wstring& new_text)
{
	this->text = new_text;
	refresh_transform();
}

void Label::set_text_height(int height)
{
	this->text_height = height;
	refresh_transform();
}

void Label::set_text_color(const COLORREF color)
{
	this->text_original_color = color;
	this->text_render_color = color;
}

void Label::set_text_handle_color(const COLORREF color)
{
	this->text_handle_color = color;
}

void Label::set_position(const Vector2& vec)
{
	Widget::set_position(vec);
	this->original_transform.set_position(vec);
}
