#include "RenderNode.h"

RenderNode::RenderNode(Transform* pTransform, bool bIsVisible) : TObject(pTransform),
m_bIsVisible(bIsVisible)
{
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

