#pragma once
#include "Platform.h"
class NormalPlatform : public Platform
{
public:
	//平台默认大小为长32像素，高8像素
	NormalPlatform(const Vector2& position = Vector2());
	~NormalPlatform() = default;
public:
	virtual bool initial() override;
};