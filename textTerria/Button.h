#pragma once
#include <easyx.h>
#include <functional>
#include <string>
#include "Widget.h"
#include "Label.h"
class Button : public Widget {
public:
	Button(Widget* parent = nullptr,const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Button();
	virtual void on_update() override;
	void set_left_click_callback(std::function<void()> on_pushed_callback);
protected:
	enum class Stage
	{
		idle,
		handle,
		push
	};
protected:
	std::function<void()> on_left_click_callback;
};