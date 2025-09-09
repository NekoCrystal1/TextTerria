#pragma once
#include "Animation.h"
class AnimationManager {
public:
	static AnimationManager* instance();

	Animation::Frame* create_frame(COLORREF fillcolor = (COLORREF)0xFFFFFF, COLORREF linecolor = (COLORREF)0xFFFFFF, bool is_filled = false, const Vector2& position = Vector2());
private:
	AnimationManager();
	~AnimationManager();

private:
	static AnimationManager* manager;
	std::vector<Animation::Frame*> frames;
};