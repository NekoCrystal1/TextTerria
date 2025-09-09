#pragma once
#include "Button.h"
#include "ItemManager.h"
class ItemButton : public Button {
public:
	ItemButton(Widget* parent = nullptr,const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~ItemButton();
	virtual void on_update() override;
	virtual void on_render() const override;
	bool update_animation();
	void set_bind_storage(Storage* storage);
	void set_item_id(short id);
	short get_item_id() const;
	Item* get_item() const;
protected:
	Storage* bind_storage;
	//将会绑定容器中一个格子的格子号
	short item_id;
};