#include "PlatformFactory.h"

NormalPlatform* PlatformFactory::tryCreateNormalPlatform(BlockId emPlatformID, const Vector2& position)
{
	NormalPlatform* pNormalPlatform = nullptr;
	switch (emPlatformID)
	{
	case BlockId::BLOCK_TEST_PLATFORM:
		pNormalPlatform = new NormalPlatform(position);
		if (!pNormalPlatform->initial())
		{
			delete pNormalPlatform;
		}
		break;
	default:
		break;
	}
    return pNormalPlatform;
}
