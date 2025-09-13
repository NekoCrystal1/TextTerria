#pragma once
#include "TComponentObject.h"
#include "TObject.h"
#include "TNodeInterface.hpp"
class RenderNode : public TObject, public TNodeInterface<RenderNode>
{
public:
	RenderNode(Transform* pTransform, bool bIsVisible = true);
	virtual ~RenderNode() = default;
public:
	virtual void onRender(float fCurTime);
protected:
	void renderNextNodes(float fCurTime);
protected:
	bool m_bIsVisible;
};