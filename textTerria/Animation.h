#pragma once
#include <easyx.h>
#include <vector>
#include "Atlas.h"
#include "Timer.h"
#include "RenderNode.h"
class Animation : public RenderNode
{
public:
	Animation();
	~Animation();
public:
	struct Frame
	{
	public:
		Frame() = default;
		~Frame() = default;
	protected:
		IMAGE* m_pImg;
	};
private:
	int m_i32CurFrameIndex;
	Timer timer;
	std::vector<Frame*> frames;
};