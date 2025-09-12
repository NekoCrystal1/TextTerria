#include "Button.h"
#include "UTIL.hpp"
#include "InputManager.h"
Button::Button(Widget* parent, const Vector2& size, const Vector2& position) :
	Widget(parent,size, position), on_left_click_callback(nullptr)
{
}

Button::~Button()
{
}

void Button::on_update()
{
	Widget::on_update();
	const ExMessage& msg = InputManager::instance()->get_mouse_msg();
	if (msg.message == WM_LBUTTONDOWN && check_point_in_rectangle(Vector2(msg.x, msg.y), *m_pTransform) &&
		on_left_click_callback && tree_event->cur_available_num) {
		on_left_click_callback();
		tree_event->cur_available_num--;
	}
}

void Button::set_left_click_callback(std::function<void()> on_pushed_callback)
{
	this->on_left_click_callback = on_pushed_callback;
}
