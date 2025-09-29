#pragma once
#include <easyx.h>
#include <vector>
#include "TNodeInterface.hpp"
/*
* 控件类
* 包含位置、背景色以及是否透明(背景/控件)
* 构造时可以设置大小及背景，透明默认均为false,背景默认白色
* 
*/
class Widget : public TNodeInterface<Widget>{
protected:
	struct WidgetEvent
	{
		//可以用于该树控件可触发次数计数
		int available_num;
		//当前可触发数
		int cur_available_num;
		WidgetEvent(int available_num = 1) :available_num(available_num) ,cur_available_num(available_num) {};
		void reset();
	};
public:
	//控件默认可见,背景及其线框不可见
	Widget(Widget* parent = nullptr, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Widget();
	virtual void on_update();
	//控件的渲染暂时使用自身函数
	virtual void on_render() const;
	//获得当前控件特定布局位置，从左上角到右下角，从左到右，从上到下，分别为0~8
	//参数2可以自动计算边缘使得目标控件边缘和当前控件边缘重合而不超出当前控件范围（放不下还是会超的）
	Vector2 get_layout(int layout_idx = 0, const Vector2& target_size = Vector2(0,0)) const;
	void set_background_color(COLORREF color);
	void set_background_frame_line_color(COLORREF color);
	void set_visiable(bool bIsVisiable = true);
	void set_all_visiable(bool is_all_visible = true);
	void set_background_visiable(bool is_background_visiable = true);
	void set_background_frame_line_visiable(bool is_background_frame_line_visiable = true);
	const std::vector<Widget*>& get_childs()const;
protected:
	bool m_bIsVisible;
	bool is_background_visiable;
	bool is_background_frame_line_visiable;
	COLORREF background_color;
	COLORREF background_frame_line_color;
	WidgetEvent* tree_event;
};