#include "TLevelManager.h"

TEntityObject* TLevelManager::getCruWorkEntityNode()
{
	return m_pCurWorkEntityNode;
}

void TLevelManager::setCurWorkEntityNode(TEntityObject* pWorkNode)
{
	if (pWorkNode)
	{
		m_pCurWorkEntityNode = pWorkNode;
	}
	else
	{
		m_pCurWorkEntityNode = getRootNode("VirtualNode");
	}
}
