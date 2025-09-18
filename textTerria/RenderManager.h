#pragma once
#include <string>
#include <unordered_map>
#include "Singleton.hpp"
#include "RenderNode.h"
#include "TNodeManagerInterface.hpp"
#define RENDER_MANAGER RenderManager::instance()
class RenderManager : public Singleton<RenderManager>, public TNodeManagerInterface<RenderNode>
{
	friend Singleton<RenderManager>;
private:
	RenderManager();
	~RenderManager();
public:
	void onRender(unsigned long long ui64CurTime);
	void clearRenderNodes();
	void eraseRenderNode(std::string sNodeName);
	//将某根节点加入到渲染队列，返回加入的节点，如果加入了不存在的节点，会返回当前工作节点
	RenderNode* addRenderNode(std::string sNodeName);
private:
	//持有将会被渲染的节点
	RenderNode* m_pRenderNode;
};