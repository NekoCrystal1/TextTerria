#pragma once
#include "ItemButton.h"
class ShortcutItemButton : public ItemButton {
public:
	ShortcutItemButton(Widget* parent = nullptr, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~ShortcutItemButton();
};