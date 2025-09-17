#include "TLevelManager.h"

TLevelManager::~TLevelManager()
{
    for (std::pair<std::string, TLevel*> i: m_mapLevelPool)
    {
        delete i.second;
    }
    m_mapLevelPool.clear();
}

TLevel* TLevelManager::createLevel(std::string sLevelName)
{
    TLevel* pLevel = new TLevel();
    return pLevel;
}

