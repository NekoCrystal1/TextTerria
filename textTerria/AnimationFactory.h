#pragma once
#include "Animation.h"
#include "RenderManager.h"
#include "Singleton.hpp"

#define ANIMATION_FACTORY AnimationFactory::instance()
class AnimationFactory : public Singleton<AnimationFactory>
{
	friend Singleton<AnimationFactory>;
private:
	AnimationFactory();
	~AnimationFactory();
public:
	//创建失败会返回nullptr
	Animation* tryCreateAnimation(IMAGE* pImg, const Vector2& position = Vector2());
	Animation* tryCreateAnimation(Atlas* pAtlas, const Vector2& position = Vector2());
	
private:
};