#pragma once
#include "Singleton.hpp"
#include "RenderNode.h"

#define RENDER_MANAGER RenderManager::instance();
class RenderManager : public Singleton<RenderManager>
{
	friend Singleton<RenderManager>;
public:
	void onRender(float fCurTime);
private:
	RenderManager();
	~RenderManager() = default;
private:
	std::vector<RenderNode*> m_vecRenderRoots;
	
};