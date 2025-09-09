#include "Storage.h"

Storage::Storage(Actor* parent, int item_solt_num) : storage_items_list(item_solt_num, nullptr), parent(parent)
{
}

Storage::~Storage()
{
	for (Item* i : storage_items_list)
		delete i;
	storage_items_list.clear();
}

void Storage::modify_in(int i, Item* item)
{
	if (i >= 0 && i < storage_items_list.size())
		storage_items_list[i] = item;
}

const std::vector<Item*>& Storage::get_list() const
{
	return storage_items_list;
}

int Storage::get_size() const
{
	return storage_items_list.size();
}

Actor* Storage::get_parent() const
{
	return this->parent;
}

Item* Storage::operator[](int i) const
{
	if(i >= 0 && i < storage_items_list.size())
		return storage_items_list[i];
	return nullptr;
}

Item* Storage::at(int i) const
{
	if (i >= 0 && i < storage_items_list.size())
		return storage_items_list[i];
	return nullptr;
}
