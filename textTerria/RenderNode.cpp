#include "RenderNode.h"
#include "Game.h"

RenderNode::RenderNode(const Vector2& size, const Vector2& position, bool bIsVisible) : 
	TWorldTransformObject(size, position), TNodeInterface(),
m_bIsVisible(bIsVisible), m_bIsTransformChanged(false),
m_ui32LastMilisecond(0), m_ui32CurCountMilisecond(0), m_pTargetTransform(new Transform(size, position))
{
}

void RenderNode::renderNextNodes(unsigned int ui32CurMilisecond)
{
	if (m_bIsTransformChanged)
	{
		//计算当前经过时间在该帧中剩余时间占比：利用该占比计算到目标状态需要的变化量
		float fTransformPerscentage = static_cast<float>(ui32CurMilisecond - m_ui32LastMilisecond) 
			/ static_cast<float>(PER_FRAME_MILISECOND - m_ui32CurCountMilisecond);
		m_ui32LastMilisecond = ui32CurMilisecond;
		m_ui32CurCountMilisecond += ui32CurMilisecond - m_ui32LastMilisecond;
		//百分比应属于0~1
		if (fTransformPerscentage > 1)
			fTransformPerscentage = 1;
		else if (fTransformPerscentage < 0)
			fTransformPerscentage = 0;

		//实现百分比变换
		m_pLocalTransform->makeTransformTo(*m_pTargetTransform, fTransformPerscentage);

		if (m_ui32CurCountMilisecond >= PER_FRAME_MILISECOND)
		{
			m_bIsTransformChanged = false;
		}
	}
	for (RenderNode* node : m_vecNextNodes)
	{
		node->onRender(ui32CurMilisecond);
	}
}

void RenderNode::onRender(unsigned long long ui32CurMilisecond)
{
	if (!m_bIsVisible)
	{
		return;
	}
	renderNextNodes(ui32CurMilisecond);
}

void RenderNode::nextFrameMoveTo(const Vector2& newPos)
{
	m_ui32CurCountMilisecond = 0;
	m_pTargetTransform->set_position(newPos);
	m_bIsTransformChanged = true;
}

