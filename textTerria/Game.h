#pragma once
#include <chrono>
#include "Singleton.hpp"
#include "MenuSence.h"
#include "GameSence.h"

const static float PER_FRAME_MILISECOND = (float)1000 / (float)60;

class Game : public Singleton<Game>
{
	friend Singleton<Game>;
public:
	bool getGameRUnning();
	void setGameRunning(bool bIsGameRunning);
	void runGame();
private:
	void initGame();
private:
	Game();
	~Game();
private:
	bool m_bIsGameRunning;
	MenuSence* m_pMainMenuScene;
	GameSence* m_pGameScene;
};
static Game* GAME = Game::instance();
