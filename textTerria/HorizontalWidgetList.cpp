//#include "HorizontalWidgetList.h"
//
//HorizontalWidgetList::HorizontalWidgetList(Widget* parent, const Vector2& position, const Vector2& size, int interval, int original_interval):
//	WidgetList(parent,position,size,interval,original_interval)
//{
//}
//
//HorizontalWidgetList::~HorizontalWidgetList()
//{
//}
//
//void HorizontalWidgetList::refresh_transform()
//{
//	transform.set_size(original_interval, max_size.y);
//	for (Widget* i : childs) {
//		i->set_position(Vector2(transform.get_position().x + transform.get_size().x, this->get_layout(3, i->get_transform().get_size()).y));
//		transform.set_size_x(transform.get_size().x + i->get_transform().get_size().x + interval);
//	}
//}
