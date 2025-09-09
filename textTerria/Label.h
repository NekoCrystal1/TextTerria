#pragma once
#include <string>
#include "Widget.h"
class Label : public Widget {
public:
	Label(Widget* parent = nullptr,const Vector2& position = Vector2(), const Vector2& size = Vector2(), bool is_handle_scale = false);
	~Label();
	void on_update() override;
	void on_render() const override;
	void refresh_transform();
	void set_text(const std::wstring& new_text);
	void set_text_height(int height);
	void set_text_color(const COLORREF color);
	void set_text_handle_color(const COLORREF color);
	void set_position(const Vector2& vec)override;
protected:
	std::wstring text;
	COLORREF text_original_color;	//标签原颜色
	COLORREF text_render_color;		//当前渲染标签色
	COLORREF text_handle_color;		//悬停时文本颜色
	int text_height;				//当前文本渲染高度
	int text_original_height;		//文本原高度
	Transform original_transform;	//标签原变换状态
	Vector2 change_scale;			//标签缩放大小
	bool is_handle_scale;			//是否开启悬停缩放
};