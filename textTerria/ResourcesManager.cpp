#include "ResourcesManager.h"
#include "UTIL.hpp"
IMAGE* ResourcesManager::createImg(std::string imgName, std::vector<POINT> points, COLORREF fillcolor, COLORREF linecolor, bool is_filled = false)
{
	int max_x = 0, max_y = 0;
	for (POINT& i : points) {
		if (max_x < i.x)
			max_x = i.x;
		if (max_y < i.y)
			max_y = i.y;
	}
	IMAGE* pImg = new IMAGE(max_x, max_y);
	SetWorkingImage(pImg);
	setfillcolor(fillcolor);
	setlinecolor(linecolor);
	switch (is_filled)
	{
	case 0:
		polygon(points.data(), points.size());
		break;
	case 1:
		fillpolygon(points.data(), points.size());
		break;
	}
	SetWorkingImage();
	m_vecImgResources.insert(std::pair<std::string, IMAGE*>(imgName, pImg));
	return pImg;
}
void ResourcesManager::loadResources()
{
	//Íæ¼Ò´óÐ¡30*80
	createImg( "PlayerImg",
		{ { 15, 0 }, { 30,13 }, { 30,40 }, { 20,40 }, { 20,70 }, { 30,70 }, { 30,80 }, { 0,80 }, { 0,70 }, { 10,70 }, { 10,40 }, { 0,40 }, { 0,13 } },
		0xAA88AA, 0xFF2200, true);

	createImg( "TestBowImg",
		{ { 0, 0 }, { 16,16 }, { 0,31 } },
		0xAAEECC, 0x000000, false);

	createImg( "TestArrowImg",
		{ {0, 13}, {32, 13}, {32, 0}, {48, 14}, {32, 27}, {32, 15}, {0, 15} },
	0xFF00FF, 0x00FF00, true);

	createImg("TestPlatformImg", 
		{ {0, 0}, {32, 0}, { 32, 8}, {0, 8} },
	0xFF0000, 0x000000, true);

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
