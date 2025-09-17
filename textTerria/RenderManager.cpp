#include "RenderManager.h"

void RenderManager::onRender(float fCurTime)
{
	m_pRenderNode->onRender(fCurTime);
}

void RenderManager::clearRenderNodes()
{
	m_pRenderNode->removeNextNodesTo(nullptr);
}

RenderNode* RenderManager::addRenderNode(std::string sNodeName)
{
	RenderNode* node = getRootNode(sNodeName);
	if (node)
	{
		node->setParentNode(m_pRenderNode);
		return node;
	}
	return m_pCurWorkNode;
}

void RenderManager::eraseRenderNode(std::string sNodeName)
{
	RenderNode* node = getRootNode(sNodeName);
	if (node)
	{
		node->setParentNode(nullptr);
	}
}

