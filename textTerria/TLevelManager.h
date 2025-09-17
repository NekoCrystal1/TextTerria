#pragma once
#include <unordered_map>
#include <string>
#include "TLevel.h"
#include "Singleton.hpp"
#define LEVEL_MANAGER TLevelManager::instance()
class TLevelManager : Singleton<TLevelManager>
{
	friend Singleton < TLevelManager>;
private:
	TLevelManager() = default;
	~TLevelManager();
public:
	TLevel* createLevel(std::string sLevelName);
	void addRoot(std::string& sNodeName);
	TLevel* getRootNode(std::string& sNodeName);
private:
	std::unordered_map<std::string, TLevel*> m_mapLevelPool;
};