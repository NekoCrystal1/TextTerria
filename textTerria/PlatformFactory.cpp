#include "PlatformFactory.h"
#include "TLevelManager.h"
Platform* PlatformFactory::tryCreatePlatform(BlockId emPlatformID, const Vector2& position)
{
	Platform* pNormalPlatform = nullptr;
	switch (emPlatformID)
	{
	case BlockId::BLOCK_NORMAL_PLATFORM:
		pNormalPlatform = new NormalPlatform(position);
		if (!pNormalPlatform->initial())
		{
			delete pNormalPlatform;
			pNormalPlatform = nullptr;
			return pNormalPlatform;
		}
		pNormalPlatform->setParentNode(LEVEL_MANAGER->getCruWorkEntityNode());
		break;
	default:
		break;
	}
    return pNormalPlatform;
}
