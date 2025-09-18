#include "BlockFactory.h"
#include "NormalBlock.h"
#include "TLevelManager.h"
Block* BlockFactory::tryCreateBlock(BlockId emBlockId, const Vector2& position)
{
    Block* pAns = nullptr;
	switch (emBlockId)
	{
	case BlockId::BLOCK_NORMAL_BLOCK:
		pAns = new NormalBlock(position);
		if (!pAns->initial())
		{
			delete pAns;
			pAns = nullptr;
			return pAns;
		}
		pAns->setParentNode(LEVEL_MANAGER->getCruWorkEntityNode());
		break;
	default:
		break;
	}
	return pAns;
}
