#pragma once
#include "Sence.h"
#include "Widget.h"
#include "Player.h"
#include "TLevel.h"
class GameSence : public Sence {
public:
	GameSence();
	~GameSence();
	virtual void on_enter()override;
	void on_update()override;
	void on_exit()override;
	void loadUI();
	void load_map();
private:
	Widget* game_background_widget;
	Player* player;
	TLevel* m_pGameLevel;
};