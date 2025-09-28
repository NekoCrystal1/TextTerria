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
		m_pLocalTransform->set_size(original_interval, max_size.y);
		for (Widget* i : childs) {
			i->setLocalPosition(Vector2(m_pLocalTransform->get_position().x + m_pLocalTransform->get_size().x, this->get_layout(alignment, i->getTransform()->get_size()).y));
			m_pLocalTransform->set_size_x(m_pLocalTransform->get_size().x + i->getTransform()->get_size().x + interval);
		}
		break;
	case WidgetList::ListMode::vertical:
		m_pLocalTransform->set_size(max_size.x, original_interval);
		for (Widget* i : childs) {
			i->setLocalPosition(Vector2(this->get_layout(alignment, i->getTransform()->get_size()).x, m_pLocalTransform->get_position().y + m_pLocalTransform->get_size().y));
			m_pLocalTransform->set_size_y(m_pLocalTransform->get_size().y + i->getTransform()->get_size().y + interval);
		}
		break;
	default:
		break;
	}
}	

void WidgetList::setLocalPosition(const Vector2& new_pos)
{
	this->setLocalPosition(new_pos.x, new_pos.y);
}

void WidgetList::setLocalPosition(float x, float y)
{
	Widget::setLocalPosition(x, y);
	refresh_transform();
}

void WidgetList::add_child(Widget* widget)
{
	if (max_size.x < widget->getTransform()->get_size().x)
		max_size.x = widget->getTransform()->get_size().x;
	if (max_size.y < widget->getTransform()->get_size().y)
		max_size.y = widget->getTransform()->get_size().y;
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

