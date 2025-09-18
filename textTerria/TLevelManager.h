#pragma once
#include <unordered_map>
#include <string>
#include "TLevel.h"
#include "Singleton.hpp"
#include "TNodeManagerInterface.hpp"

/*
* 作为关卡管理类，不仅管理各个关卡
* 还管理关卡中的TEntityObject的实体关系：如物品可以绑定在角色身上，也可以掉落在关卡中，利用该类进行控制
*/

#define LEVEL_MANAGER TLevelManager::instance()
class TLevelManager : public Singleton<TLevelManager>, public TNodeManagerInterface<TLevel>
{
	friend Singleton < TLevelManager>;
private:
	TLevelManager() = default;
	~TLevelManager() = default;
public:
	TEntityObject* getCruWorkEntityNode();
	//传入nullptr会被重定向为TLevel:VirtualNode
	void setCurWorkEntityNode(TEntityObject* pWorkNode);
private:
	TEntityObject* m_pCurWorkEntityNode;
};