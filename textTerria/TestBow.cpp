#include "TestBow.h"
#include "TObjectManager.h"
TestBow::TestBow(Storage* included_storage) : Item(included_storage, 1)
{
	item_frame = AnimationManager::instance()->create_frame(0xAAEECC, 0x000000, false, transform->get_position());
	this->item_frame->set_points(std::vector<POINT>({
		{0,0},{16,16},{0,31}
		}));
}

void TestBow::on_use()
{
	//printf("fire");
	Arrow* arrow = TObjectManager::instance()->create_arrow(this->included_storage->get_parent(),
		this->included_storage->get_parent()->get_transform()->get_position());

}
