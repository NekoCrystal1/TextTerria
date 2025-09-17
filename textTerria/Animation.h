#pragma once
#include <easyx.h>
#include <vector>
#include "Atlas.h"
#include "MilisecondTimer.h"
#include "RenderNode.h"
class Animation : public RenderNode
{
public:
	//使用RenderManager中的当前工作节点作为父节点：可在场景切换时自行修改，如果需要更换，可以修改RenderManager工作节点或者使用setParent
	Animation(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	Animation(IMAGE* pImg, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	Animation(Atlas* pAtlas, const Vector2& size = Vector2(), const Vector2& position = Vector2());
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
	virtual void onRender(unsigned int ui32CurMilisecond) override;
	void addImg(IMAGE* img);
private:
	int m_i32CurFrameIndex;
	//MilisecondTimer m_oTimer;
	std::vector<Frame*> m_vecFrames;
};