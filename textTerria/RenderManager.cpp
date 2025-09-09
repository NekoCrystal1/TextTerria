#include "RenderManager.h"

void RenderManager::onRender(float fCurTime)
{
	m_pRootNode->onRender(fCurTime);
}

RenderManager::RenderManager() : m_pRootNode(new RenderNode())
{
}

RenderManager::~RenderManager()
{
	delete m_pRootNode;
}
