#pragma once
#include "Sence.h"
#include "Widget.h"
#include "Player.h"
class GameSence : public Sence {
public:
	GameSence();
	~GameSence();
	void on_update()override;
	void on_enter()override;
	void on_exit()override;
	void load_map();
private:
	Widget* game_background_widget;
	Player* player;
};