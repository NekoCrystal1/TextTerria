#include <easyx.h>
#include <chrono>
#include <iostream>
#include "SenceManager.h"
#include "MenuSence.h"
#include "GameSence.h"
#include "InputManager.h"
#include "CollisionManager.h"
bool is_game_runing = 1;
const static float per_frame_milisecond = (float)1000 / (float)60;
MenuSence* main_menu_sence;
GameSence* game_sence;
Camera* camera;
void initGame() {
	initgraph(1280, 720);
	setbkmode(TRANSPARENT);
	camera = Camera::instance();
	main_menu_sence = new MenuSence();
	SenceManager::instance()->add_sence("menu", main_menu_sence);
	game_sence = new GameSence();
	SenceManager::instance()->add_sence("game", game_sence);
	SenceManager::instance()->switch_to("menu");
}
int main() {
	initGame();
	ExMessage msg;
	auto cur_time = std::chrono::high_resolution_clock::now();
	auto last_time = cur_time;
	int delta = 0;
	//IMAGE* temp = new IMAGE(100,100);
	int frames = 0;//记录经过帧数->计算每秒帧数
	int timer = 0;//记录经过时间
	BeginBatchDraw();
	while (is_game_runing) {
		//input
		while (peekmessage(&msg))
		{
			camera->on_input(msg);
			InputManager::instance()->on_input(msg);
		}
		cur_time = std::chrono::high_resolution_clock::now();
		delta += (cur_time - last_time).count() / 1000000;
		last_time = cur_time;
		while (delta > per_frame_milisecond) {
			timer++;
			if (timer > 60) {
				timer -= 60;
				std::cout << "当前每秒帧数：" << frames << "\n";
				frames = 0;
			}
			//update
			camera->on_uodate();
			SenceManager::instance()->on_update();
			InputManager::instance()->on_update();
			delta -= per_frame_milisecond;
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
	return 0;
}