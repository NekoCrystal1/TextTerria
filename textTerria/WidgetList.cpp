#include "WidgetList.h"

WidgetList::WidgetList(Widget* parent, ListMode listmode, int alignment, int interval, int original_interval):	Widget(parent),
interval(interval), original_interval(original_interval), max_size(), list_mode(listmode), alignment(alignment)
{
}

WidgetList::~WidgetList()
{
}

void WidgetList::refresh_transform()
{
	switch (list_mode)
	{
	case WidgetList::ListMode::horizontal:
		transform->set_size(original_interval, max_size.y);
		for (Widget* i : childs) {
			i->set_position(Vector2(transform->get_position().x + transform->get_size().x, this->get_layout(alignment, i->get_transform()->get_size()).y));
			transform->set_size_x(transform->get_size().x + i->get_transform()->get_size().x + interval);
		}
		break;
	case WidgetList::ListMode::vertical:
		transform->set_size(max_size.x, original_interval);
		for (Widget* i : childs) {
			i->set_position(Vector2(this->get_layout(alignment, i->get_transform()->get_size()).x, transform->get_position().y + transform->get_size().y));
			transform->set_size_y(transform->get_size().y + i->get_transform()->get_size().y + interval);
		}
		break;
	default:
		break;
	}
}	

void WidgetList::set_position(const Vector2& new_pos)
{
	Widget::set_position(new_pos);
	refresh_transform();
}

void WidgetList::set_position(float x, float y)
{
	set_position(Vector2(x, y));
	refresh_transform();
}

void WidgetList::add_child(Widget* widget)
{
	if (max_size.x < widget->get_transform()->get_size().x)
		max_size.x = widget->get_transform()->get_size().x;
	if (max_size.y < widget->get_transform()->get_size().y)
		max_size.y = widget->get_transform()->get_size().y;
	childs.push_back(widget);
	//在基类中实现时每次添加控件都需要刷新，有较大的性能开销，可以将其放入子类直接实现以减少开销
	refresh_transform();
}

void WidgetList::set_interval(int interval)
{
	this->interval = interval;
	refresh_transform();
}

void WidgetList::set_original_interval(int interval)
{
	this->original_interval = original_interval;
	refresh_transform();
}

