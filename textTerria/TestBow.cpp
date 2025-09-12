#include "TestBow.h"
#include "TObjectManager.h"
TestBow::TestBow(Storage* included_storage) : Item(included_storage, 1)
{
}

void TestBow::on_use()
{
	//printf("fire");
	Arrow* arrow = TObjectManager::instance()->create_arrow(this->included_storage->get_parent(),
		this->included_storage->get_parent()->getTransform()->get_position());

}
