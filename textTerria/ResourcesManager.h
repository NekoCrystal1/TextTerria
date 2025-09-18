#pragma once
#include <easyx.h>
#include <string>
#include <unordered_map>
#include "Atlas.h"
#include "Singleton.hpp"

#define RESOURCES_MANAGER ResourcesManager::instance()
class ResourcesManager : public Singleton<ResourcesManager>
{
	friend Singleton<ResourcesManager>;
public:
	void loadResources();
	IMAGE* createImg(std::string imgName, std::vector<POINT> points, COLORREF fillcolor, COLORREF linecolor, bool is_filled);
	IMAGE* getImage(std::string strImgName) const;
	Atlas* getAtlas(std::string strAtlasName) const;
private:
	ResourcesManager() = default;
	~ResourcesManager();
private:
	std::unordered_map<std::string, IMAGE*> m_vecImgResources;
	std::unordered_map<std::string, Atlas*> m_vecAtlasResources;
};