#pragma once
#include <chrono>
#include "Singleton.hpp"
#include "SenceManager.h"
#include "MenuSence.h"
#include "GameSence.h"
#include "InputManager.h"
#include "CollisionManager.h"

class Game : public Singleton<Game>
{
	friend Singleton<Game>;
public:
	bool getIsGameRunning();
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
