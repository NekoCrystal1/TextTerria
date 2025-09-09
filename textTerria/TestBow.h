#pragma once
#include "Item.h"
class TestBow : public Item {
public:
	TestBow(Storage* included_storage) ;
	virtual ~TestBow() = default;
	virtual void on_use() override;
private:
};