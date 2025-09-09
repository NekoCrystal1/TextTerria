#pragma once
#include "Animation.h"
#include "Singleton.hpp"
class AnimationManager : public Singleton<AnimationManager>
{
	friend Singleton<AnimationManager>;
public:
private:
	AnimationManager();
	~AnimationManager();

private:
};