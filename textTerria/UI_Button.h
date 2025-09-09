#pragma once
#include "Button.h"
#include "ItemButton.h"
class UI_Button : public ItemButton{
public:
	UI_Button(Widget* parent = nullptr, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~UI_Button() = default;
	virtual void on_render() const override;

protected:
	bool is_item_visible;
};