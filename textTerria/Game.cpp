#include "Game.h"
#include <iostream>
#include "CollisionManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourcesManager.h"
#include "SenceManager.h"

Game::Game() : m_bIsGameRunning(true), m_pMainMenuScene(nullptr), m_pGameScene(nullptr)
{
}

Game::~Game()
{
}

void Game::initGame()
{
	initgraph(1280, 720);
	setbkmode(TRANSPARENT);
	RESOURCES_MANAGER->loadResources();

	//m_pMainMenuScene = new MenuSence();
	m_pGameScene = new GameSence();
	//SenceManager::instance()->add_sence("menu", m_pMainMenuScene);
	SenceManager::instance()->add_sence("game", m_pGameScene);

	//先忽略UI相关
	SenceManager::instance()->switch_to("game");
}

void Game::runGame()
{
	initGame();
	ExMessage msg;
	auto cur_time = std::chrono::high_resolution_clock::now();
	auto last_time = cur_time;
	//变化的毫秒数
	unsigned int delta = 0;
	//IMAGE* temp = new IMAGE(100,100);
	int frames = 0;//记录经过帧数->计算每秒帧数
	int timer = 0;//记录经过时间
	BeginBatchDraw();
	while (m_bIsGameRunning) {
		//input
		while (peekmessage(&msg))
		{
			CAMERA->on_input(msg);
			InputManager::instance()->on_input(msg);
		}
		cur_time = std::chrono::high_resolution_clock::now();
		delta += (cur_time - last_time).count() / 1000000;
		last_time = cur_time;
		while (delta > PER_FRAME_MILISECOND) {
			timer++;
			if (timer > 60) {
				timer -= 60;
				std::cout << "当前每秒帧数：" << frames << "\n";
				frames = 0;
			}
			//update
			CAMERA->on_update();
			SenceManager::instance()->on_update();
			InputManager::instance()->on_update();
			delta -= PER_FRAME_MILISECOND;
		}
		//render
		cleardevice();

		//使用Rendermanger
		//SenceManager::instance()->on_render();
		RENDER_MANAGER->onRender(std::chrono::duration_cast<std::chrono::milliseconds>(cur_time.time_since_epoch()).count());
		FlushBatchDraw();
		frames++;
		Sleep(1);
	}
	EndBatchDraw();
	closegraph();

}

bool Game::getGameRUnning()
{
	return this->m_bIsGameRunning;
}

void Game::setGameRunning(bool bIsGameRunning)
{
	m_bIsGameRunning = bIsGameRunning;
}
