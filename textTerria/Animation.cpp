#include "Animation.h"
#include "UTIL.hpp"

Animation::Animation() : RenderNode(), m_i32CurFrameIndex(0)
{
}

Animation::Animation(IMAGE* pImg) : RenderNode(), m_i32CurFrameIndex(0), m_vecFrames(1,new Frame(pImg))
{
}

Animation::Animation(Atlas* atlas) : RenderNode(), m_i32CurFrameIndex(0), m_vecFrames()
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
		const Vector2& oCurPos = m_Transform.get_position();
		const Vector2& oCurSize = m_Transform.get_size();
		IMAGE* pImg = m_vecFrames[m_i32CurFrameIndex]->getImg();
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

IMAGE* Animation::Frame::getImg()
{
	return m_pImg;
}
