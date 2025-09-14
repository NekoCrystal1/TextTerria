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

Item* ItemManager::create_Item(Storage* included_storage, ItemId id, bool can_stack, short number)
{
    Item* item = nullptr;
    switch (id)
    {
    case ItemId::ITEM_TEST_BOW:
        item = new TestBow(included_storage);
        break;
    case ItemId::ITEM_TEST_GUN:
        break;
    default:
        item = Item::get_null_item();
        break;
    }
    return item;
}

ItemManager::ItemManager() {
}

ItemManager::~ItemManager()
{
}
