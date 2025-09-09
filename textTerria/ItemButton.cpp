#include "ItemButton.h"

ItemButton::ItemButton(Widget* parent, const Vector2& size, const Vector2& position) : Button(parent,size, position),
bind_storage(nullptr), item_id(-1), item_frame(AnimationManager::instance()->create_frame())
{
}

ItemButton::~ItemButton()
{
}

void ItemButton::on_update()
{
	const Vector2& pos = transform->get_position();
	const Vector2& size = transform->get_size();
	item_frame->set_position(pos + (size - item_frame->get_transform().get_size()) * 0.5f);
	Button::on_update();
}

void ItemButton::on_render() const
{
	if (!is_visiable)
		return;
	Button::on_render();
	item_frame->on_render_ui();
}

bool ItemButton::update_animation()
{
	if (bind_storage && bind_storage->at(item_id)) {
		*item_frame = *bind_storage->at(item_id)->get_frame();
		return true;
	}
	return false;
}

void ItemButton::set_bind_storage(Storage* storage)
{
	this->bind_storage = storage;
	update_animation();
}

void ItemButton::set_item_id(short id)
{
	this->item_id = id;
	update_animation();
}

short ItemButton::get_item_id() const
{
	return item_id;
}

Item* ItemButton::get_item() const
{
	if(bind_storage)
		return bind_storage->at(item_id);
	return nullptr;
}
