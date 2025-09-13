#pragma once
#include <vector>

template<typename T>
class TNodeInterface
{
public:
	TNodeInterface();
	virtual ~TNodeInterface();
public:
	//自动根据层级添加
	void addNode(T* pNextNode);
	//直接尾插：将会改变目标层级为最高层
	void pushBack(T* pNextNode);
	void setOrder(int i32Order);
	T* getParentNode();
protected:
	//当前渲染层级：渲染顺序，先渲染当前节点，然后渲染子节点，子节点排序根据层级由小到大排序，因此先渲染层级小的，默认0级
	int m_Order;
	//根据层级从小到大排序，层级越小越先渲染；同层级会根据加入顺序决定；移除当前节点会将子节点都移除
	std::vector<T*> m_vecNextNodes;
	//改变层级后会调整父层级中的列表
	T* m_pParentNode;
};

template<typename T>
inline TNodeInterface<T>::TNodeInterface()
{
}

template<typename T>
inline TNodeInterface<T>::~TNodeInterface()
{
	//clearVec(this->m_vecNextNodes);
}

template<typename T>
inline void TNodeInterface<T>::addNode(T* pNextNode)
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

template<typename T>
inline void TNodeInterface<T>::pushBack(T* pNextNode)
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

template<typename T>
inline void TNodeInterface<T>::setOrder(int i32Order)
{
	if (!m_pParentNode)
	{
		m_Order = i32Order;
		return;
	}

	int i32PastIndex = -1;
	std::vector<T*>& vecParentNextNodes = m_pParentNode->m_vecNextNodes;
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

template<typename T>
inline T* TNodeInterface<T>::getParentNode()
{
	return m_pParentNode;
}
