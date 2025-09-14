#pragma once
#include "NormalPlatform.h"
#include "Singleton.hpp"
#include "GameId.h"

#define PLATFORM_FACTORY PlatformFactory::instance()
class PlatformFactory : public Singleton<PlatformFactory>
{
	friend Singleton<PlatformFactory>;
public:
	//尝试在指定位置创建平台，如果返回nullptr则创建失败
	NormalPlatform* tryCreateNormalPlatform(BlockId emPlatformID, const Vector2& position);
private:
	PlatformFactory() = default;
	~PlatformFactory() = default;
private:

};