#pragma once
#include <vector>
#include "TObject.h"
#include "UTIL.hpp"

//T类必为模板类子类
template<typename T>
class TNodeInterface : public TObject
{
public:
	//允许父节点为空
	TNodeInterface(const Transform& oLocalTransform = Transform());
	TNodeInterface(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~TNodeInterface();
//坐标变换
public:
	virtual const Transform& getWorldTransform();
	//实现原理：修改本地位置，使其在计算完相对坐标后位于目标位置，如果没有继承节点树，则默认直接修改
	void setWorldPosition(const Vector2& newPos);
	void setWorldSize(const Vector2& newSize);
	virtual void setLocalPosition(const Vector2& position)override;
	virtual void setLocalPosition(float x, float y)override;
	virtual void setLocalAnchor(const Vector2& oNewAnchor)override;
	void makeDirty();
protected:
	virtual void updateTransform();

public:
	//获取的是vector引用
	std::vector<T*>& getNextNodes();
	T* getParentNode();
	void setOrder(int i32Order);
	//修改自身父节点，执行之后还需要尝试更新坐标
	virtual void setParentNode(T* pNewParent);
	//将子节点移入目标节点
	void removeNextNodesTo(T* pNewParent);
protected:
	//由于移除需要改变pTarget的父节点，但是T*不具备此功能，所以使用setParent来控制
	void eraseNode(T* pTarget);
	//自动根据层级添加，protected理由同上
	void addNode(T* pNextNode);
	//直接尾插：将会改变目标层级为最高层
	void pushBack(T* pNextNode);
	//将自身从父节点移除
	virtual void removeFromParent();
protected:
	//当前渲染层级：渲染顺序，先渲染当前节点，然后渲染子节点，子节点排序根据层级由小到大排序，因此先渲染层级小的，默认0级
	int m_i32Order;
	//根据层级从小到大排序，层级越小越先渲染；同层级会根据加入顺序决定；移除当前节点会将子节点都移除
	std::vector<T*> m_vecNextNodes;
	//改变层级后会调整父层级中的列表
	T* m_pParentNode;
	//父节点及自身改变会导致世界坐标需要更新，在get时更新
	bool m_bIsTransformDirty;
	Transform* m_pWorldTransform;
};

template<typename T>
inline TNodeInterface<T>::TNodeInterface(const Transform& oLocalTransform) : TObject(new Transform(oLocalTransform)),
	 m_bIsTransformDirty(true), m_pWorldTransform(new Transform()),
	m_i32Order(0), m_vecNextNodes(), m_pParentNode(nullptr)
{
}

template<typename T>
inline TNodeInterface<T>::TNodeInterface(const Vector2& size, const Vector2& position): TObject(new Transform(size, position)), 
	m_bIsTransformDirty(true), m_pWorldTransform(new Transform()),
	m_i32Order(0), m_vecNextNodes(), m_pParentNode(nullptr)
{
}

template<typename T>
inline TNodeInterface<T>::~TNodeInterface()
{
	delete m_pLocalTransform;
	m_pLocalTransform = nullptr;
	delete m_pWorldTransform;
	m_pWorldTransform = nullptr;

	//先将所有子节点的父节点置空：自身所有子节点均无需remove（因为他们的父节点也会被释放）
	for (TNodeInterface<T>* node : m_vecNextNodes)
	{
		node->m_pParentNode = nullptr;
	}
	clearVec(this->m_vecNextNodes);
	//将自身从父节点中移除
	removeFromParent();
}

template<typename T>
inline const Transform& TNodeInterface<T>::getWorldTransform()
{
	if (m_bIsTransformDirty)
	{
		updateTransform();
		m_bIsTransformDirty = false;
	}
	return *m_pWorldTransform;
}

template<typename T>
inline void TNodeInterface<T>::setWorldPosition(const Vector2& newPos)
{
	makeDirty();
	if (!this->getParentNode())
	{
		this->setLocalPosition(newPos);
		return;
	}
	this->setLocalPosition(newPos - static_cast<TNodeInterface<T>*>(this->getParentNode())->getWorldTransform().get_position());
}

template<typename T>
inline void TNodeInterface<T>::setWorldSize(const Vector2& newSize)
{

}

template<typename T>
inline void TNodeInterface<T>::setLocalPosition(const Vector2& position)
{
	setLocalPosition(position.x, position.y);
}

template<typename T>
inline void TNodeInterface<T>::setLocalPosition(float x, float y)
{
	TObject::setLocalPosition(x, y);
	makeDirty();
}

template<typename T>
inline void TNodeInterface<T>::setLocalAnchor(const Vector2& oNewAnchor)
{
	TObject::setLocalAnchor(oNewAnchor);
	makeDirty();
}

template<typename T>
inline void TNodeInterface<T>::makeDirty()
{
	m_bIsTransformDirty = true;
	for (TNodeInterface<T>* node : this->getNextNodes())
	{
		node->makeDirty();
	}
}

template<typename T>
inline void TNodeInterface<T>::updateTransform()
{
	if (!this->getParentNode())
	{
		*m_pWorldTransform = *m_pLocalTransform;
		return;
	}
	*m_pWorldTransform = *m_pLocalTransform + static_cast<TNodeInterface<T>*>(this->getParentNode())->getWorldTransform();
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
		if (pNextNode->m_i32Order < m_vecNextNodes[i]->m_i32Order)
		{
			m_vecNextNodes.insert(m_vecNextNodes.begin() + i, pNextNode);
			bHasAdd = true;
			break;
		}
	}
	TNodeInterface<T>* pNext = static_cast<TNodeInterface<T>*>(pNextNode);
	pNext->m_pParentNode = static_cast<T*>(this);
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
		pNextNode->m_i32Order = m_vecNextNodes.back()->m_i32Order;
	}
	m_vecNextNodes.push_back(pNextNode);
	TNodeInterface<T>* pNext = static_cast<TNodeInterface<T>*>(pNextNode);
	pNext->m_pParentNode = this;
}

template<typename T>
inline void TNodeInterface<T>::removeFromParent()
{
	TNodeInterface<T>* pParent = static_cast<TNodeInterface<T>*>(m_pParentNode);
	if (pParent)
	{
		pParent->eraseNode(static_cast<T*>(this));
		makeDirty();
	}
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
			if (i == 0 || vecParentNextNodes[i - 1]->m_i32Order < i32Order)
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
			if (i == i32VecEndIndex || vecParentNextNodes[i + 1]->m_i32Order > i32Order)
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
inline void TNodeInterface<T>::setParentNode(T* pNewParent)
{
	TNodeInterface<T>* pParent = static_cast<TNodeInterface<T>*>(m_pParentNode);
	if (pParent)
	{
		pParent->eraseNode(static_cast<T*>(this));
	}
	this->m_pParentNode = pNewParent; 
	if (pNewParent)
	{
		pNewParent->addNode(static_cast<T*>(this));
	}
	makeDirty();
}

template<typename T>
inline void TNodeInterface<T>::removeNextNodesTo(T* pNewParent)
{
	for (T* i : m_vecNextNodes)
	{
		TNodeInterface<T>* node = static_cast<TNodeInterface<T>*>(i);
		node->m_pParentNode = pNewParent;
		if (pNewParent)
		{
			pNewParent->addNode(static_cast<T*>(node));
		}
	}
	m_vecNextNodes.clear(); 
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

