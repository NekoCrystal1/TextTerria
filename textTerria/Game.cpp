#include "Game.h"
#include <iostream>


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
	m_pMainMenuScene = new MenuSence();
	m_pGameScene = new GameSence();
	SenceManager::instance()->add_sence("menu", m_pMainMenuScene);
	SenceManager::instance()->add_sence("game", m_pGameScene);
	SenceManager::instance()->switch_to("menu");
}

void Game::runGame()
{
	initGame();
	ExMessage msg;
	auto cur_time = std::chrono::high_resolution_clock::now();
	auto last_time = cur_time;
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
			CAMERA->on_uodate();
			SenceManager::instance()->on_update();
			InputManager::instance()->on_update();
			delta -= PER_FRAME_MILISECOND;
		}
		//render
		cleardevice();
		SenceManager::instance()->on_render();
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
