#pragma once
#include "TWorldTransformObject.h"
#include "TNodeInterface.hpp"
class RenderNode : public TWorldTransformObject, public TNodeInterface<RenderNode>
{
	defaultWorldTransformVirtualFuncInNode;
public:
	RenderNode(const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool bIsVisible = true);
	virtual ~RenderNode() = default;
public:
	virtual void onRender(unsigned long long ui32CurMilisecond);
	void nextFrameMoveTo(const Vector2& newPos);
protected:
	void renderNextNodes(unsigned int ui32CurMilisecond);
protected:
	unsigned int m_ui32LastMilisecond;
	unsigned int m_ui32CurCountMilisecond;
	bool m_bIsVisible;
	bool m_bIsTransformChanged;
	//父节点及自身改变会导致世界坐标需要更新，在get时更新
	bool m_bIsTransformDirty;
	Transform* m_pWorldTransform;
	Transform* m_pTargetTransform;
};