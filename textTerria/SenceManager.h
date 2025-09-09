#pragma once
#include <easyx.h>
#include <unordered_map>
#include <string>
#include "Sence.h"
#include "Camera.h"
class SenceManager {
public:
	static SenceManager* instance();

	void on_update();
	void on_render()const;
	void switch_to(std::string target);
	void add_sence(std::string name, Sence* new_sence);
	void set_cur_sence(Sence* sence);
private:
	SenceManager();
	~SenceManager();
private:
	static SenceManager* manager;
private:
	Sence* cur_sence;
	std::unordered_map<std::string, Sence*> sences;
};