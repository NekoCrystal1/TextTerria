#pragma once
#include <easyx.h>
#include <vector>
#include "Atlas.h"
#include "MilisecondTimer.h"
#include "RenderNode.h"
class Animation : public RenderNode
{
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
	//使用RenderManager中的当前工作节点作为父节点：可在场景切换时自行修改，如果需要更换，可以修改RenderManager工作节点或者使用setParent
	Animation(const Vector2& position = Vector2(), bool bIsAttachCamera = true);
	~Animation();
public:
	//初始化时若因所需资源无法获取等，将会返回false，此函数必须调用，因此请在工厂中实例化
	bool initial(IMAGE* pImg);
	bool initial(Atlas* pAtlas);
	virtual void renderFunc(unsigned long long ui32CurMilisecond) override;
	void addImg(IMAGE* img);
private:
	bool m_bIsAttachCamera;
	int m_i32CurFrameIndex;
	std::vector<Frame*> m_vecFrames;
};