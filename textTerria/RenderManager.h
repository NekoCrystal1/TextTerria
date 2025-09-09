#pragma once
#include "Singleton.hpp"
#include "RenderNode.h"
class RenderManager : public Singleton<RenderManager>
{
	friend Singleton<RenderManager>;
public:
	void onRender();
private:
	RenderManager();
	~RenderManager();
private:
	RenderNode* m_pRootNode;
};