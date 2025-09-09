#pragma once
#include "Actor.h"
#include "Timer.h"
class Storage;
class Item : public TObject {
private:
	static Item* null_item;
public:
	static Item* get_null_item();
public:
	Item(Storage* included_storage, int id = 0, bool can_stack = 0, short number = 1);
	virtual ~Item();
	virtual void on_update();
	virtual void on_render() const;
	virtual void on_use();
protected:
	int id;
	short number;
	//是否可堆叠
	bool can_stack;
	//物品功能使用cd定时器
	Timer* use_cd_timer;
	//被存在哪个容器中
	Storage* included_storage;
};