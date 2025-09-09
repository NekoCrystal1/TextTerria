#pragma once
#include <easyx.h>
#include <vector>
#include "Vector2.h"
#include "Atlas.h"
#include "Timer.h"
#include "Camera.h"

#include "RenderNode.h"
class Animation : public RenderNode
{
public:
	Animation(const Vector2& position = Vector2(0,0));
	~Animation();
public:
	struct Frame
	{
	public:
		//创建的帧无形状，需要使用set_points创建形状
		Frame(COLORREF fillcolor = (COLORREF)0xFFFFFF, COLORREF linecolor = (COLORREF)0xFFFFFF, bool is_filled = false, const Vector2& position = Vector2());
		~Frame();
		virtual void on_render() const;
		virtual void on_render_ui() const;
		const Transform& get_transform()const;
		void set_points(const std::vector<POINT>& points);
		void set_position(const Vector2& position);
		void set_position(float x, float y);
		void refresh_size();
	protected:
		std::vector<POINT> points;
		Transform transform;
		COLORREF fillcolor;
		COLORREF linecolor;
		bool is_filled;
	};
private:
	int m_i32CurFrameIndex;
	Timer timer;
	std::vector<Frame*> frames;
};