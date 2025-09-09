#include "Widget.h"

Widget::Widget(Widget* parent, const Vector2& size, const Vector2& position) :
	TObject(size, position, true), is_background_visiable(false), is_background_frame_line_visiable(false), background_color(0xFFFFFF), background_frame_line_color(0xFFFFFF),
	parent(parent), childs(), tree_event(nullptr)
{
	if (parent) {
		parent->add_child(this);
		tree_event = parent->tree_event;
	}
	else
		tree_event = new WidgetEvent();
}

Widget::~Widget() {
	if (parent)
		parent->remove_child(this);
	for (Widget* c : childs)
		delete c;
	childs.clear();
}

void Widget::on_update()
{
	for (Widget* c : childs)
		c->on_update();
	if (!parent)
		tree_event->reset();
}

void Widget::on_render() const
{
	if (!is_visiable)
		return;
	if (is_background_visiable) {
		setlinecolor(this->background_frame_line_color);
		setfillcolor(this->background_color);
		const Vector2& pos = transform->get_position();
		const Vector2& size = transform->get_size();
		fillrectangle(pos.x, pos.y, pos.x + size.x, pos.y + size.y);
	}
	for (Widget* p : childs)
		p->on_render();
}

void Widget::add_child(Widget* child)
{
	if(child && child != this)
		this->childs.push_back(child);
}

void Widget::remove_child(Widget* child)
{
	auto it = std::find(childs.begin(), childs.end(),child);
	if (it != childs.end())
		childs.erase(it);
}

Vector2 Widget::get_layout(int layout_idx, const Vector2& target_size) const
{
	Vector2 size = transform->get_size();
	Vector2 ans = Vector2();
	switch (layout_idx)
	{
	case 0:
		ans = Vector2(0, 0);
		break;
	case 1:
		ans = Vector2(size.x / 2 - target_size.x / 2, 0);
		break;
	case 2:
		ans = Vector2(size.x - target_size.x, 0);
		break;
	case 3:
		ans = Vector2(0, size.y / 2 - target_size.y / 2);
		break;
	case 4:
		ans = Vector2(size.x / 2 - target_size.x / 2, size.y / 2 - target_size.y / 2);
		break;
	case 5:
		ans = Vector2(size.x - target_size.x, size.y / 2 - target_size.y / 2);
		break;
	case 6:
		ans = Vector2(0, size.y - target_size.y);
		break;
	case 7:
		ans = Vector2(size.x / 2 - target_size.x / 2, size.y - target_size.y);
		break;
	case 8:
		ans = Vector2(size.x - target_size.x, size.y - target_size.y);
		break;
	}
	return ans + transform->get_position();
}

void Widget::set_background_color(COLORREF color)
{
	this->background_color = color;
}

void Widget::set_background_frame_line_color(COLORREF color)
{
	this->background_frame_line_color = color;
}

void Widget::set_all_visiable(bool is_all_visible)
{
	this->is_visiable = is_all_visible;
	this->is_background_visiable = is_all_visible;
	this->is_background_frame_line_visiable = is_all_visible;
}

void Widget::set_background_visiable(bool is_background_visiable)
{
	this->is_background_visiable = is_background_visiable;
}

void Widget::set_background_frame_line_visiable(bool is_background_frame_line_visiable)
{
	this->is_background_frame_line_visiable = is_background_frame_line_visiable;
}

const std::vector<Widget*>& Widget::get_childs() const
{
	return childs;
}

void Widget::WidgetEvent::reset()
{
	this->cur_available_num = available_num;
}
