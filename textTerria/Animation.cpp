#include "Animation.h"
#include "RenderManager.h"
#include "UTIL.hpp"

Animation::Animation(const Vector2& size = Vector2(), const Vector2& position = Vector2()) :
	RenderNode(RENDER_MANAGER->gerCruWorkNode(), size, position), m_i32CurFrameIndex(0)
{
}

Animation::Animation(const Vector2& size = Vector2(), const Vector2& position = Vector2(), IMAGE* pImg) : 
	RenderNode(RENDER_MANAGER->gerCruWorkNode(), size, position), m_i32CurFrameIndex(0), m_vecFrames(1,new Frame(pImg))
{
}

Animation::Animation(const Vector2& size = Vector2(), const Vector2& position = Vector2(), Atlas* atlas) :
	RenderNode(RENDER_MANAGER->gerCruWorkNode(), size, position), m_i32CurFrameIndex(0), m_vecFrames()
{
}

Animation::~Animation()
{
	clearVec(m_vecFrames);
}

void Animation::onRender(unsigned int ui32CurMilisecond)
{
	if (!m_bIsVisible)
	{
		return;
	}
	if (m_i32CurFrameIndex < m_vecFrames.size())
	{
		Frame* pCurFrame = m_vecFrames[m_i32CurFrameIndex];
		IMAGE* pImg = pCurFrame->m_pImg;
		const Vector2& oCurPos = m_pLocalTransform->get_position();
		Vector2 oCurSize = pCurFrame->m_pTransform.get_size();
		oCurSize.only_multiply_every_element_modify_self(m_pLocalTransform->get_scale());
		putImage(oCurPos.x, oCurPos.y, oCurSize.x, oCurSize.y, pImg, 0, 0, pImg->getwidth(), pImg->getheight());
	}

	renderNextNodes(ui32CurMilisecond);
}

void Animation::addImg(IMAGE* img)
{
	Frame* frame = new Frame(img);
	m_vecFrames.push_back(frame);
}

Animation::Frame::Frame(IMAGE* pImg) : m_pImg(pImg)
{
}
