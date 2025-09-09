#include "AnimationManager.h"

Animation::Frame* AnimationManager::create_frame(COLORREF fillcolor, COLORREF linecolor, bool is_filled, const Vector2& position)
{
	frames.push_back(new Animation::Frame(fillcolor,linecolor, is_filled, position));
	return frames.back();
}

AnimationManager::AnimationManager()
{
}
AnimationManager::~AnimationManager()
{
}
