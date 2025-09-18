#include "PlayerFactory.h"
#include "TLevelManager.h"
Player* PlayerFactory::createPlayer(const Vector2& position)
{
	Player* pAns = new Player(position);
	if (!pAns->initial())
	{
		delete pAns;
		pAns = nullptr;
		return pAns;
	}
	pAns->setParentNode(LEVEL_MANAGER->getCruWorkEntityNode());
	return pAns;
}
