#include "RenderNode.h"

RenderNode::RenderNode() : m_bIsVisible(true), m_Order(0), m_pParentNode(nullptr)
{
}

RenderNode::~RenderNode()
{
	for (int i = 0; i < m_vecNextNodes.size(); i++)
	{
		delete m_vecNextNodes[i];
	}
	m_vecNextNodes.clear();
}

void RenderNode::renderNextNodes()
{
	for (RenderNode* node : m_vecNextNodes)
	{
		node->onRender();
	}
}

void RenderNode::onRender()
{
	if (!m_bIsVisible)
	{
		return;
	}
	renderNextNodes();
}

void RenderNode::addNode(RenderNode* pNextNode)
{
	if (!pNextNode)
		return;
	pNextNode->m_pParentNode = this;
	bool bHasAdd = false;
	for (int i = 0; i < m_vecNextNodes.size(); i++)
	{
		if (pNextNode->m_Order < m_vecNextNodes[i]->m_Order)
		{
			m_vecNextNodes.insert(m_vecNextNodes.begin() + i, pNextNode);
			bHasAdd = true;
			break;
		}
	}
	//如果子节点为空或者加入节点最大，则尾插
	if (!bHasAdd)
	{
		m_vecNextNodes.push_back(pNextNode);
	}
}

void RenderNode::pushBack(RenderNode* pNextNode)
{
	if (!pNextNode)
		return;
	pNextNode->m_pParentNode = this;
	if (!m_vecNextNodes.empty())
	{
		pNextNode->m_Order = m_vecNextNodes.back()->m_Order;
	}
	m_vecNextNodes.push_back(pNextNode);
}

void RenderNode::setOrder(int i32Order)
{
	if (!m_pParentNode)
	{
		m_Order = i32Order;
		return;
	}

	int i32PastIndex = -1;
	for (int i = 0; i < m_vecNextNodes.size(); i++)
	{
		if (m_vecNextNodes[i] == this)
		{
			i32PastIndex = i;
			break;
		}
	}
	//层级减小：左移
	if (m_Order > i32Order)
	{
		for (int i = i32PastIndex; i >= 0; i--)
		{
			if (i == 0 || m_vecNextNodes[i - 1]->m_Order < i32Order)
			{
				m_vecNextNodes[i] = this;
				break;
			}
			else
			{
				m_vecNextNodes[i] = m_vecNextNodes[i - 1];
			}
		}
	}
	//层级增大、不变（相当于刷新也需要移动）：右移
	else
	{
		int i32VecEndIndex = m_vecNextNodes.size() - 1;
		for (int i = i32PastIndex; i <= i32VecEndIndex; i++)
		{
			if (i == i32VecEndIndex || m_vecNextNodes[i + 1]->m_Order > i32Order)
			{
				m_vecNextNodes[i] = this;
				break;
			}
			else
			{
				m_vecNextNodes[i] = m_vecNextNodes[i + 1];
			}
		}
	}
	m_Order = i32Order;
}
