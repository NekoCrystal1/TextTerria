#include "TLevelManager.h"

TLevelManager::TLevelManager() : m_pCurWorkEntityNode(getRootNode("VirtualNode"))
{
}


TEntityObject* TLevelManager::getCruWorkEntityNode()
{
	if (!m_pCurWorkEntityNode)
	{
		m_pCurWorkEntityNode = getRootNode("VirtualNode");
	}
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
