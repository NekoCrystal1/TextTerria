#pragma once
#include "Widget.h"
class WidgetTree {
private:
	struct WidgetNode
	{
		Widget* current_widget;
		Widget* brother_widget;
		Widget* next_widget;
		WidgetNode(Widget* cur_widget, Widget* brother_widget = nullptr, Widget* next_widget = nullptr) :current_widget(cur_widget), brother_widget(brother_widget), next_widget(next_widget) {};
	};
public:
	WidgetTree();
	~WidgetTree();
	void add_node(Widget* cur_widget, Widget* brother_widget = nullptr, Widget* next_widget = nullptr);
private:
	WidgetNode* virtual_root;
};