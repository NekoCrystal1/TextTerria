#include "UI_Button.h"

UI_Button::UI_Button(Widget* parent, const Vector2& size, const Vector2& position) : ItemButton(parent, size, position),
is_item_visible(false)
{
}

void UI_Button::on_render() const
{
	if (!is_visiable)
		return;
	Button::on_render();
	if(is_item_visible)
		item_frame->on_render_ui();
}
