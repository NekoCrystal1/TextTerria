#pragma once
#include "Character.h"
#include "Storage.h"
#include "Animation.h"
const static Vector2 PLAYER_SIZE = { 26, 80 };

class Player : public Character{
public:
	Player(const Vector2& position = Vector2());
	~Player();
	virtual bool initial() override;
	virtual void on_update()override;
	Storage* get_storage() const;
private:
	Storage* bag_pack;
	//将会绑定back中一个格子的格子号
	short main_hand_slot_id;
};