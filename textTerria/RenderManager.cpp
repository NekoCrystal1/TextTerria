#include "RenderManager.h"
RenderManager::RenderManager() : TNodeManagerInterface(),
m_pRenderNode(new RenderNode())
{
}

RenderManager::~RenderManager()
{
	delete m_pRenderNode;
	m_pRenderNode = nullptr;
}

void RenderManager::onRender(unsigned long long ui64CurTime)
{
	m_pRenderNode->onRender(ui64CurTime);
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

