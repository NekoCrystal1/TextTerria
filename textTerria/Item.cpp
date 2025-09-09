#include "Item.h"
Item* Item::null_item = new Item(nullptr);

Item* Item::get_null_item()
{
	if (!null_item)
		null_item = new Item(nullptr);
	return null_item;
}

Item::Item(Storage* included_storage, int id, bool can_stack, short number) :TObject(),
	id(id), can_stack(can_stack), number(number), use_cd_timer(new Timer(60,false)),item_frame(nullptr),included_storage(included_storage)
{
	is_visiable = true;
}

Item::~Item()
{
	delete use_cd_timer;
}

void Item::on_update()
{
	use_cd_timer->on_update();
}

void Item::on_render() const
{
	if (!is_visiable)
		return;
	if(item_frame)
		item_frame->on_render();
}

void Item::on_use()
{
}

const Animation::Frame* Item::get_frame() const
{
	return this->item_frame;
}
