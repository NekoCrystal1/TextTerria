#pragma once
#include "Block.h"
#include "GameId.h"
#include "Singleton.hpp"

#define BLOCK_FACTORY BlockFactory::instance()
class BlockFactory : public Singleton<BlockFactory>
{
	friend Singleton<BlockFactory>;
public:
	Block* tryCreateBlock(BlockId emBlockId, const Vector2& position);
private:
	BlockFactory() = default;
	~BlockFactory() = default;
};