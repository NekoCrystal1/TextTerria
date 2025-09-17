#pragma once
#include "Character.h"
#include "Storage.h"
class Player : public Character{
public:
	Player(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Player();
	virtual void on_update()override;
	virtual void setLocalPosition(const Vector2& pos) override;
	virtual void setLocalPosition(float x, float y) override;
	Storage* get_storage() const;
private:
	Storage* bag_pack;
	//将会绑定back中一个格子的格子号
	short main_hand_slot_id;
};