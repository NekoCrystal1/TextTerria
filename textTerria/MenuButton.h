#pragma once
#include "Button.h"
class Menu_Button : public Button{
public:
	Menu_Button(Widget* parent = nullptr,const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Menu_Button();
	void on_update() override;
	void on_render() const override;
	void set_pushed_callback(std::function<void()> on_pushed_callback);
	void set_text(const std::wstring& new_text);
	void set_text_height(int height);
	void set_text_color(const COLORREF color);
	void set_text_handle_color(const COLORREF color);
	void set_text_visiable(bool visiable = true);
	void setLocalPosition(const Vector2& vec)override;
protected:
	Label* label;
};