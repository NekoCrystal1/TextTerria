#pragma once
#include "Item.h"
class Storage {
public:
	Storage(Actor* parent, int item_solt_num = 1);
	~Storage();

	Item* operator[](int i) const;
	Item* at(int i) const;
	void modify_in(int i, Item* item);
	const std::vector<Item*>& get_list() const;
	int get_size() const;
	Actor* get_parent() const;
private:
	//背包格子数
	//int item_solt_num;
	//背包列表，渲染时可以自行决定怎么渲染（比如m行n列）
	std::vector<Item*> storage_items_list;
	//背包属于的对象
	Actor* parent;
};