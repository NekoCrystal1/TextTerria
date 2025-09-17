#include "RenderManager.h"

RenderManager::RenderManager()
{
	m_pCurWorkNode = addRoot("VirtualNode");
}
RenderManager::~RenderManager()
{
	for (auto i : m_mapRenderRoots)
	{
		delete i.second;
	}
}

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

RenderNode* RenderManager::addRoot(std::string sNodeName)
{
	RenderNode* pNode = new RenderNode(nullptr);
	m_mapRenderRoots.insert(std::pair<std::string, RenderNode*>(sNodeName, pNode));
	return pNode;	
}

RenderNode* RenderManager::getRootNode(std::string sNodeName)
{
	auto ans = m_mapRenderRoots.find(sNodeName);
	if (ans != m_mapRenderRoots.end())
	{
		return ans->second;
	}
	return nullptr;
}

RenderNode* RenderManager::gerCruWorkNode()
{
	return m_pCurWorkNode;
}

void RenderManager::setCurWorkNode(RenderNode* pWorkNode)
{
	if (pWorkNode)
	{
		m_pCurWorkNode = pWorkNode;
	}
	else
	{
		m_pCurWorkNode = getRootNode("VirtualNode");
	}
}
