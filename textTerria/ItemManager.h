#pragma once
#include "Storage.h"
class ItemManager {
private:
	static ItemManager* manager;
public:
	static ItemManager* instance();
	Storage* create_storage(Actor* parent, int solt_num = 1);
public:
	Item* create_Item(Storage* included_storage, ItemId id, bool can_stack = 0, short number = 1);
private:
	ItemManager();
	~ItemManager();
private:
	//Storage* cur_storage;
};