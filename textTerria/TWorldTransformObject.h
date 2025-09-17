#pragma once
#include "TObject.h"
#include <vector>

#define defaultSetWorldPositionInNode()\
{\
	if (!m_pParentNode)\
	{\
		m_pWorldTransform->set_position(newPos);\
		return;\
	}\
	m_pWorldTransform->set_position(newPos - m_pParentNode->getWorldTransform().get_position());\
}

#define defaultUpdateTransformInNode()\
{\
	if (!m_pParentNode)\
	{\
		m_pWorldTransform = m_pLocalTransform;\
		return;\
	}\
	*m_pWorldTransform = *m_pLocalTransform + m_pParentNode->getWorldTransform();\
}

#define defaultMakeDirtyInNode()\
{\
	m_bIsTransformDirty = true;\
	for (TWorldTransformObject* node : m_vecNextNodes)\
	{\
		node->makeDirty();\
	}\
}

#define defaultWorldTransformVirtualFuncInNode \
public:\
	virtual void setWorldPosition(const Vector2& newPos)override{defaultSetWorldPositionInNode();};\
protected:\
	virtual void updateTransform()override{defaultUpdateTransformInNode();};\
	virtual void makeDirty()override{defaultMakeDirtyInNode();};

class TWorldTransformObject : public TObject
{
public:
	TWorldTransformObject(const Transform& oLocalTransform);
	TWorldTransformObject(const Vector2& size, const Vector2& position);
	virtual ~TWorldTransformObject();
public:
	virtual const Transform& getWorldTransform();
	//实现原理：修改本地位置，使其在计算完相对坐标后位于目标位置，如果没有继承节点树，则默认直接修改
	virtual void setWorldPosition(const Vector2& newPos);
	virtual void makeDirty() = 0;
protected:
	virtual void updateTransform() = 0;
protected:
	//父节点及自身改变会导致世界坐标需要更新，在get时更新
	bool m_bIsTransformDirty;
	Transform* m_pWorldTransform;
};