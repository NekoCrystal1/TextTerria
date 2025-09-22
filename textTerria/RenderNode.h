#pragma once
#include "TNodeInterface.hpp"

class RenderNode : public TNodeInterface<RenderNode>
{
public:
	RenderNode(const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool bIsVisible = true);
	virtual ~RenderNode() = default;
public:
	void onRender(unsigned long long ui32CurMilisecond);
	void nextFrameMoveTo(const Vector2& newPos);
	void nextFrameMoveTo(float x, float y);
protected:
	virtual void renderFunc(unsigned long long ui32CurMilisecond);	
	virtual void renderTransform(unsigned long long ui32CurMilisecond);
	void renderNextNodes(unsigned int ui32CurMilisecond);
protected:
	unsigned int m_ui32LastMilisecond;
	unsigned int m_ui32CurCountMilisecond;
	bool m_bIsVisible;
	bool m_bIsTransformChanged;
	Transform* m_pTargetTransform;
};