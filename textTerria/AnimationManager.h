#pragma once
#include "Animation.h"
#include "Singleton.hpp"
class AnimationManager : public Singleton<AnimationManager>
{
	friend Singleton<AnimationManager>;
public:
	Animation::Frame* create_frame(COLORREF fillcolor = (COLORREF)0xFFFFFF, COLORREF linecolor = (COLORREF)0xFFFFFF, bool is_filled = false, const Vector2& position = Vector2());
private:
	AnimationManager();
	~AnimationManager();

private:
	std::vector<Animation::Frame*> frames;
};