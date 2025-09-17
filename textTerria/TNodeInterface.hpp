#pragma once
#include <vector>
#include "UTIL.hpp"

#define defaultSetParent(TypeName) \
public:\
virtual void setParentNode(TypeName##* pNewParent)override\
{\
	if (m_pParentNode)\
	{\
		m_pParentNode->eraseNode(this);\
	}\
	this->m_pParentNode = pNewParent;\
	if(pNewParent)\
	{\
		pNewParent->addNode(this); \
	}\
}

#define defaultRemoveNextNodesTo(TypeName) \
public:\
virtual void removeNextNodesTo(TypeName##* pNewParent)override\
{\
	for(TypeName##* node : m_vecNextNodes)\
	{\
		node->m_pParentNode = pNewParent;\
		if(pNewParent)\
		{\
			pNewParent.addNode(node); \
		}\
	}\
	m_vecNextNodes.clear();\
}

template<typename T>
class TNodeInterface
{
public:
	//允许父节点为空
	TNodeInterface(T* pParent);
	virtual ~TNodeInterface();
public:
	//获取的是vector引用
	std::vector<T*>& getNextNodes();
	T* getParentNode();
	void setOrder(int i32Order);
	virtual void setParentNode(T* pNewParent) = 0;
	virtual void removeNextNodesTo(T* pNewParent) = 0;
protected:
	//由于移除需要改变pTarget的父节点，但是T*不具备此功能，所以使用setParent来控制
	void eraseNode(T* pTarget);
	//自动根据层级添加，protected理由同上
	void addNode(T* pNextNode);
	//直接尾插：将会改变目标层级为最高层
	void pushBack(T* pNextNode);
protected:
	//当前渲染层级：渲染顺序，先渲染当前节点，然后渲染子节点，子节点排序根据层级由小到大排序，因此先渲染层级小的，默认0级
	int m_i32Order;
	//根据层级从小到大排序，层级越小越先渲染；同层级会根据加入顺序决定；移除当前节点会将子节点都移除
	std::vector<T*> m_vecNextNodes;
	//改变层级后会调整父层级中的列表
	T* m_pParentNode;
};

template<typename T>
inline TNodeInterface<T>::TNodeInterface(T* pParent) : m_i32Order(0), m_vecNextNodes(), m_pParentNode(pParent)
{
}

template<typename T>
inline TNodeInterface<T>::~TNodeInterface()
{
	clearVec(this->m_vecNextNodes);
}

template<typename T>
inline void TNodeInterface<T>::addNode(T* pNextNode)
{
	if (!pNextNode)
		return;
	bool bHasAdd = false;
	for (int i = 0; i < m_vecNextNodes.size(); i++)
	{
		if (pNextNode == m_vecNextNodes[i])
		{
			//不可重复添加
			return;
		}
		if (pNextNode->m_Order < m_vecNextNodes[i]->m_Order)
		{
			m_vecNextNodes.insert(m_vecNextNodes.begin() + i, pNextNode);
			bHasAdd = true;
			break;
		}
	}
	pNextNode->m_pParentNode = this;
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
	if (std::find(m_vecNextNodes.begin(), m_vecNextNodes.end(), pNextNode) != m_vecNextNodes.end())
	{
		//不可重复添加
		return;
	}
	if (!m_vecNextNodes.empty())
	{
		pNextNode->m_Order = m_vecNextNodes.back()->m_Order;
	}
	m_vecNextNodes.push_back(pNextNode);
	pNextNode->m_pParentNode = this;

}

template<typename T>
inline void TNodeInterface<T>::setOrder(int i32Order)
{
	if (!m_pParentNode)
	{
		m_i32Order = i32Order;
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
	if (m_i32Order > i32Order)
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
	m_i32Order = i32Order;

}

template<typename T>
inline std::vector<T*>& TNodeInterface<T>::getNextNodes()
{
	return m_vecNextNodes;
}

template<typename T>
inline T* TNodeInterface<T>::getParentNode()
{
	return m_pParentNode;
}

template<typename T>
inline void TNodeInterface<T>::eraseNode(T* pTarget)
{
	for (int i = 0; i < m_vecNextNodes.size(); i++)
	{
		if (m_vecNextNodes[i] == pTarget)
		{
			m_vecNextNodes.erase(m_vecNextNodes.begin() + i);
			return;
		}
	}
}
