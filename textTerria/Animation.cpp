#include "Animation.h"
#include "UTIL.hpp"

Animation::Animation(TObject* pBindObj) : RenderNode(), m_pBindObj(pBindObj), m_i32CurFrameIndex(0)
{
}

Animation::Animation(TObject* pBingObj, IMAGE* pImg) : RenderNode(), m_pBindObj(pBingObj), m_i32CurFrameIndex(0), m_vecFrames(1,new Frame(pImg))
{
}

Animation::Animation(TObject* pBingObj, Atlas* atlas) : RenderNode(), m_pBindObj(pBingObj), m_i32CurFrameIndex(0), m_vecFrames()
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
		Vector2 oCurPos = m_Transform->get_position();
		Vector2 oCurSize = pCurFrame->m_pTransform.get_size();
		oCurSize.only_multiply_every_element_modify_self(m_Transform->get_scale());
		if (m_pBindObj)
		{
			oCurPos += m_pBindObj->get_transform()->get_position();
			oCurSize.only_multiply_every_element_modify_self(m_pBindObj->get_transform()->get_scale());
		}
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
