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
public:
	bool getGameRUnning();
	void setGameRunning(bool bIsGameRunning);
	void runGame();
private:
	void initGame();
private:
	bool m_bIsGameRunning = 1;
	MenuSence* m_pMainMenuScene;
	GameSence* m_pGameScene;
	Camera* m_pCamera;
};
