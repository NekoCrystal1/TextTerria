#pragma once
#include "Storage.h"
class ItemManager {
private:
	static ItemManager* manager;
public:
	static ItemManager* instance();
	Storage* create_storage(Actor* parent, int solt_num = 1);
public:
	enum class item_to_id
	{
		null,
		test_bow,
		test_gun,
		test_sowrd,
		test_staff,
		test_summon_staff,
	};
	Item* create_Item(Storage* included_storage, int id = 0, bool can_stack = 0, short number = 1);
	Item* create_Item(Storage* included_storage, item_to_id id, bool can_stack = 0, short number = 1);
private:
	ItemManager();
	~ItemManager();
private:
	//Storage* cur_storage;
};