#pragma once
#include <easyx.h>
#include <vector>
#include "Atlas.h"
#include "MilisecondTimer.h"
#include "RenderNode.h"
class Animation : public RenderNode
{
public:
	Animation();
	Animation(IMAGE* pImg);
	Animation(Atlas* atlas);
	~Animation();
public:
	struct Frame
	{
		Frame(IMAGE* pImg);
		~Frame() = default;
		IMAGE* getImg();
	protected:
		IMAGE* m_pImg;
		Transform m_pTransform;
	};
public:
	virtual void onRender(float fCurTime) override;
	void addImg(IMAGE* img);
private:
	int m_i32CurFrameIndex;
	MilisecondTimer m_oTimer;
	std::vector<Frame*> m_vecFrames;
};