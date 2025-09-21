#pragma once
#include <vector>
#include "TObject.h"

//继承该类的节点必须继承TNode模板（否则坐标变换将没有意义）
template<typename T>
class TWorldTransformObject : public TObject
{
protected:
	TWorldTransformObject(const Transform& oLocalTransform);
	TWorldTransformObject(const Vector2& size, const Vector2& position);
	virtual ~TWorldTransformObject();
public:
	virtual const Transform& getWorldTransform();
	//实现原理：修改本地位置，使其在计算完相对坐标后位于目标位置，如果没有继承节点树，则默认直接修改
	void setWorldPosition(const Vector2& newPos);
	void setWorldSize(const Vector2& newSize);
	void makeDirty();
protected:
	virtual void updateTransform();
protected:
	//父节点及自身改变会导致世界坐标需要更新，在get时更新
	bool m_bIsTransformDirty;
	Transform* m_pWorldTransform;
};

template<typename T>
TWorldTransformObject<T>::TWorldTransformObject(const Transform& oLocalTransform) :
	TObject(new Transform(oLocalTransform)), m_bIsTransformDirty(true),
	m_pWorldTransform(new Transform())
{
}

template<typename T>
TWorldTransformObject<T>::TWorldTransformObject(const Vector2& size, const Vector2& position) :
	TObject(new Transform(size, position)), m_bIsTransformDirty(true),
	m_pWorldTransform(new Transform())
{
}

template<typename T>
TWorldTransformObject<T>::~TWorldTransformObject()
{
	delete m_pLocalTransform;
	m_pLocalTransform = nullptr;
	delete m_pWorldTransform;
	m_pWorldTransform = nullptr;
}

template<typename T>
const Transform& TWorldTransformObject<T>::getWorldTransform()
{
	if (m_bIsTransformDirty)
	{
		updateTransform();
	}
	return *m_pWorldTransform;
}

template<typename T>
void TWorldTransformObject<T>::setWorldPosition(const Vector2& newPos)
{
	T* pNode = static_cast<T*>(this);
	if (!pNode->getParentNode())
	{
		m_pWorldTransform->set_position(newPos);
		return;
	}
	m_pWorldTransform->set_position(newPos - pNode->getParentNode()->getWorldTransform().get_position());
}

template<typename T>
inline void TWorldTransformObject<T>::makeDirty()
{
	T* pNode = static_cast<T*>(this);
	m_bIsTransformDirty = true;
	for (TWorldTransformObject* node : pNode->getNextNodes())
	{
		node->makeDirty();
	}
}

template<typename T>
inline void TWorldTransformObject<T>::updateTransform()
{
	T* pNode = static_cast<T*>(this);
	if (!pNode->getParentNode())
	{
		m_pWorldTransform = m_pLocalTransform;
		return;
	}
	*m_pWorldTransform = *m_pLocalTransform + pNode->getParentNode()->getWorldTransform();
}
