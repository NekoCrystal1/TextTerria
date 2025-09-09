#include "ItemButton.h"

ItemButton::ItemButton(Widget* parent, const Vector2& size, const Vector2& position) : Button(parent,size, position),
bind_storage(nullptr), item_id(-1)
{
}

ItemButton::~ItemButton()
{
}

void ItemButton::on_update()
{
	const Vector2& pos = m_Transform->get_position();
	const Vector2& size = m_Transform->get_size();
	Button::on_update();
}

void ItemButton::on_render() const
{
	if (!m_bIsVisible)
		return;
	Button::on_render();
}

bool ItemButton::update_animation()
{
	if (bind_storage && bind_storage->at(item_id)) {
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
