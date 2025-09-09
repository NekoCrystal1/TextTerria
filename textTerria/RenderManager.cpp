#include "RenderManager.h"

void RenderManager::onRender()
{
	m_pRootNode->onRender();
}

RenderManager::RenderManager() : m_pRootNode(new RenderNode())
{
}

RenderManager::~RenderManager()
{
	delete m_pRootNode;
}
