#include "Animation.h"
#include "Camera.h"
#include "RenderManager.h"
#include "UTIL.hpp"

Animation::Animation(const Vector2& position, bool bIsAttachCamera) :
	RenderNode(Vector2(), position), m_i32CurFrameIndex(0),m_bIsAttachCamera(true)
{
}

Animation::~Animation()
{
	clearVec(m_vecFrames);
}

bool Animation::initial(IMAGE* pImg)
{
	if (pImg)
	{
		m_vecFrames.reserve(1);
		m_vecFrames.emplace_back(new Frame(pImg));
		return true;
	}
	return false;
}

bool Animation::initial(Atlas* pAtlas)
{
	if (pAtlas)
	{
		m_vecFrames.reserve(pAtlas->getSize());
		for (IMAGE* pImg : pAtlas->getImgs())
		{
			m_vecFrames.emplace_back(new Frame(pImg));
		}
		return true;
	}
	return false;
}

void Animation::onRender(unsigned long long ui32CurMilisecond)
{
	if (!m_bIsVisible)
	{
		return;
	}
	if (m_i32CurFrameIndex < m_vecFrames.size())
	{
		Frame* pCurFrame = m_vecFrames[m_i32CurFrameIndex];
		IMAGE* pImg = pCurFrame->m_pImg;
		Vector2 oCurPos = m_pLocalTransform->get_position();
		Vector2 oCurSize = pCurFrame->m_pTransform.get_size();
		if (m_bIsAttachCamera)
		{
			Transform oRenderTransform = getWorldTransform();
			oRenderTransform.set_size(oCurSize);
			oRenderTransform = CAMERA->transformRenderTransform(oRenderTransform);
			oCurPos = oRenderTransform.get_position();
			oCurSize = oRenderTransform.get_size();
		}
		else
		{
			oCurSize.only_multiply_every_element_modify_self(m_pLocalTransform->get_scale());
		}
		putImage(oCurPos.x, oCurPos.y, oCurSize.x, oCurSize.y, pImg, 0, 0, pImg->getwidth(), pImg->getheight());
	}
	renderNextNodes(ui32CurMilisecond);
}

void Animation::addImg(IMAGE* img)
{
	Frame* frame = new Frame(img);
	m_vecFrames.push_back(frame);
}

Animation::Frame::Frame(IMAGE* pImg) : m_pImg(pImg), m_pTransform(Vector2(pImg->getwidth(), pImg->getheight()))
{
}
