#pragma once
#include <vector>
#include "Widget.h"
class WidgetList : public Widget{
public:
	enum class ListMode
	{
		horizontal,
		vertical,
	};
public:
	WidgetList(Widget* parent = nullptr, ListMode listmode = ListMode::vertical, int alignment = 1, int interval = 0, int original_interval = 0);
	virtual ~WidgetList();
	virtual void refresh_transform();
	void setLocalPosition(const Vector2& new_pos);
	void setLocalPosition(float x, float y);
	void add_child(Widget* child) override;
	void set_interval(int interval);
	void set_original_interval(int interval);
protected:
	int original_interval;
	int interval;
	//存储最大控件的size以用于预测开始绘制的行或列的起始位置
	Vector2 max_size;
	ListMode list_mode;
	//对齐方式，同set_layout，可以修改排列时对齐方式，如居中、以左上角为原点等
	int alignment;
};
