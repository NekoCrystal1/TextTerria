#pragma once
#include <unordered_map>
#include <string>
#include "TLevel.h"
#include "Singleton.hpp"
#include "TNodeManagerInterface.hpp"
#define LEVEL_MANAGER TLevelManager::instance()
class TLevelManager : public Singleton<TLevelManager>, public TNodeManagerInterface<TLevel>
{
	friend Singleton < TLevelManager>;
private:
	TLevelManager() = default;
	~TLevelManager() = default;
};