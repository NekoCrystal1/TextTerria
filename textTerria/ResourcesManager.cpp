#include "ResourcesManager.h"
#include "UTIL.hpp"
void ResourcesManager::loadResources()
{

}

IMAGE* ResourcesManager::getImage(std::string strImgName) const
{
	return m_vecImgResources.find(strImgName)->second;
}

Atlas* ResourcesManager::getAtlas(std::string strAtlasName) const
{
	return m_vecAtlasResources.find(strAtlasName)->second;
}

ResourcesManager::~ResourcesManager()
{
	for (auto i : m_vecImgResources)
	{
		delete i.second;
	}
	for (auto i : m_vecAtlasResources)
	{
		delete i.second;
	}
}
