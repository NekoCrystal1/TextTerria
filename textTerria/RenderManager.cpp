#include "RenderManager.h"

void RenderManager::onRender(float fCurTime)
{
	m_pRootNode->onRender(float fCurTime);
}

RenderManager::RenderManager() : m_pRootNode(new RenderNode())
{
}

RenderManager::~RenderManager()
{
	delete m_pRootNode;
}
