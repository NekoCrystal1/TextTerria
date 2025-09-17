#pragma once
#include <string>
#include <unordered_map>
#include "Singleton.hpp"
#include "RenderNode.h"

#define RENDER_MANAGER RenderManager::instance()
class RenderManager : public Singleton<RenderManager>
{
	friend Singleton<RenderManager>;
private:
	RenderManager();
	~RenderManager();
public:
	void onRender(float fCurTime);
	void clearRenderNodes();
	void eraseRenderNode(std::string sNodeName);
	//将某根节点加入到渲染队列，返回加入的节点，如果加入了不存在的节点，会返回当前工作节点
	RenderNode* addRenderNode(std::string sNodeName);
	RenderNode* addRoot(std::string sNodeName);
	RenderNode* getRootNode(std::string sNodeName);
	RenderNode* gerCruWorkNode();
	//传入nullptr会被重定向为virtualNode
	void setCurWorkNode(RenderNode* pWorkNode);;
private:
	//负责持有所有根节点
	std::unordered_map<std::string, RenderNode*> m_mapRenderRoots;
	//持有将会被渲染的节点
	RenderNode* m_pRenderNode;
	RenderNode* m_pCurWorkNode;
};