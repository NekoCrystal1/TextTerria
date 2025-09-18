#pragma once
#include "Block.h"

//ÆÕÍ¨·½¿é32*32
class NormalBlock : public Block
{
public:
	NormalBlock(const Vector2& position = Vector2());
	~NormalBlock() = default;
public:
	virtual bool initial() override;
};