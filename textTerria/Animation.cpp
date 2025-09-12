#include "Animation.h"
#include "UTIL.hpp"

Animation::Animation(Transform* pTransform) : RenderNode(pTransform), m_i32CurFrameIndex(0)
{
}

Animation::Animation(Transform* pTransform, IMAGE* pImg) : RenderNode(pTransform), m_i32CurFrameIndex(0), m_vecFrames(1,new Frame(pImg))
{
}

Animation::Animation(Transform* pTransform, Atlas* atlas) : RenderNode(pTransform), m_i32CurFrameIndex(0), m_vecFrames()
{
}

Animation::~Animation()
{
	clearVec(m_vecFrames);
}

void Animation::onRender(float fCurTime)
{
	if (!m_bIsVisible)
	{
		return;
	}
	if (m_i32CurFrameIndex < m_vecFrames.size())
	{
		Frame* pCurFrame = m_vecFrames[m_i32CurFrameIndex];
		IMAGE* pImg = pCurFrame->m_pImg;
		Vector2 oCurPos = m_pTransform->get_position();
		Vector2 oCurSize = pCurFrame->m_pTransform.get_size();
		oCurSize.only_multiply_every_element_modify_self(m_pTransform->get_scale());
		putImage(oCurPos.x, oCurPos.y, oCurSize.x, oCurSize.y, pImg, 0, 0, pImg->getwidth(), pImg->getheight());
	}

	renderNextNodes(fCurTime);
}

void Animation::addImg(IMAGE* img)
{
	Frame* frame = new Frame(img);
	m_vecFrames.push_back(frame);
}

Animation::Frame::Frame(IMAGE* pImg) : m_pImg(pImg)
{
}
