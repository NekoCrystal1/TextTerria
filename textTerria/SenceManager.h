#pragma once
#include <unordered_map>
#include <string>
#include "Sence.h"
#include "Singleton.hpp"
#define SENCE_MANAGER SenceManager::instance()
class SenceManager : public Singleton<SenceManager>
{
	friend Singleton<SenceManager>;
public:
	void on_update();
	void on_render()const;
	void switch_to(std::string target);
	void add_sence(std::string name, Sence* new_sence);
	void set_cur_sence(Sence* sence);
private:
	SenceManager();
	~SenceManager() = default;
private:
	Sence* cur_sence;
	std::unordered_map<std::string, Sence*> sences;
};