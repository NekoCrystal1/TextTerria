#include "RenderNode.h"

RenderNode::RenderNode(Transform* pTransform, bool bIsVisible) : TComponentObject(pTransform),
m_bIsVisible(bIsVisible), m_Order(0), m_pParentNode(nullptr)
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

void RenderNode::renderNextNodes(float fCurTime)
{
	for (RenderNode* node : m_vecNextNodes)
	{
		node->onRender(fCurTime);
	}
}

void RenderNode::onRender(float fCurTIme)
{
	if (!m_bIsVisible)
	{
		return;
	}
	renderNextNodes(fCurTIme);
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
	std::vector<RenderNode*>& vecParentNextNodes = m_pParentNode->m_vecNextNodes;
	for (int i = 0; i < vecParentNextNodes.size(); i++)
	{
		if (vecParentNextNodes[i] == this)
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
			if (i == 0 || vecParentNextNodes[i - 1]->m_Order < i32Order)
			{
				vecParentNextNodes[i] = this;
				break;
			}
			else
			{
				vecParentNextNodes[i] = vecParentNextNodes[i - 1];
			}
		}
	}
	//层级增大、不变（相当于刷新也需要移动）：右移
	else
	{
		int i32VecEndIndex = vecParentNextNodes.size() - 1;
		for (int i = i32PastIndex; i <= i32VecEndIndex; i++)
		{
			if (i == i32VecEndIndex || vecParentNextNodes[i + 1]->m_Order > i32Order)
			{
				vecParentNextNodes[i] = this;
				break;
			}
			else
			{
				vecParentNextNodes[i] = vecParentNextNodes[i + 1];
			}
		}
	}
	m_Order = i32Order;
}
