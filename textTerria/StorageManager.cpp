#include "ItemManager.h"
#include "TestBow.h"
ItemManager* ItemManager::manager = nullptr;
ItemManager* ItemManager::instance()
{
    if (!manager)
        manager = new ItemManager();
    return manager;
}

Storage* ItemManager::create_storage(Actor* parent, int solt_num)
{
    return new Storage(parent, solt_num);
}

Item* ItemManager::create_Item(Storage* included_storage, int id, bool can_stack, short number)
{
    Item* item = nullptr;
    switch (id)
    {
    case 1:
        item = new TestBow(included_storage);
        break;
    case 2:
        break;
    default:
        item = Item::get_null_item();
        break;
    }
    return item;
}

Item* ItemManager::create_Item(Storage* included_storage, item_to_id id, bool can_stack, short number)
{
    return create_Item(included_storage, (int)id, can_stack, number);
}

ItemManager::ItemManager() {
}

ItemManager::~ItemManager()
{
}
