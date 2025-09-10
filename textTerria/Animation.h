#pragma once
#include <easyx.h>
#include <vector>
#include "Atlas.h"
#include "MilisecondTimer.h"
#include "RenderNode.h"
class Animation : public RenderNode
{
public:
	Animation(Transform* pTransform);
	Animation(Transform* pTransform, IMAGE* pImg);
	Animation(Transform* pTransform, Atlas* atlas);
	~Animation();
protected:
	struct Frame
	{
		Frame(IMAGE* pImg);
		~Frame() = default;
	public:
		IMAGE* m_pImg;
		Transform m_pTransform;
	};
public:
	virtual void onRender(float fCurTime) override;
	void addImg(IMAGE* img);
private:
	int m_i32CurFrameIndex;
	//MilisecondTimer m_oTimer;
	std::vector<Frame*> m_vecFrames;
};