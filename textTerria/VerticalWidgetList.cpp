//#include "VerticalWidgetList.h"
//
//VerticalWidgetList::VerticalWidgetList(Widget* parent, const Vector2& position, const Vector2& size, int interval, int original_interval):
//	WidgetList(parent,position,size,interval,original_interval)
//{
//}
//
//VerticalWidgetList::~VerticalWidgetList()
//{
//}
//
//void VerticalWidgetList::refresh_transform()
//{
//	transform.set_size(max_size.x, original_interval);
//	for (int i = 0; i < childs.size(); i++) {
//		childs[i]->set_position(Vector2(this->get_layout(1, childs[i]->get_transform().get_size()).x, transform.get_position().y + transform.get_size().y));
//		transform.set_size_y(transform.get_size().y + childs[i]->get_transform().get_size().y + interval);
//	}
//}
