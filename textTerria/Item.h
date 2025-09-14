#pragma once
#include "Actor.h"
#include "Timer.h"
#include "GameId.h"
class Storage;
class Item : public Actor {
private:
	static Item* null_item;
public:
	static Item* get_null_item();

public:
	Item(Storage* included_storage, ItemId id = ItemId::ITEM_NULL, bool can_stack = 0, short number = 1);
	virtual ~Item();
	virtual void on_update();
	virtual void on_use();
protected:
	ItemId id;
	short number;
	//是否可堆叠
	bool can_stack;
	//物品功能使用cd定时器
	Timer* use_cd_timer;
	//被存在哪个容器中
	Storage* included_storage;
};