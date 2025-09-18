#include "ResourcesManager.h"
#include "UTIL.hpp"
//COLORREF:BGR
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
	//由于颜色存在alpha通道，原始绘制产生的图片全为0，因此需将每个不透明像素的不透明度改成1，由于无法区分透明与黑色，如果原来的黑色0会变透明：黑色应取1
	DWORD* pImgBuffer = GetImageBuffer(pImg);
	for (unsigned int i = 0; i < max_x * max_y; i++)
	{
		if(pImgBuffer[i] != 0x00000000)
			pImgBuffer[i] |= 0xFF000000;
	}
	SetWorkingImage();
	m_vecImgResources.insert(std::pair<std::string, IMAGE*>(imgName, pImg));
	saveimage(_T("debug_createImg_output.png"), pImg);
	return pImg;
}
void ResourcesManager::loadResources()
{
	//玩家大小30*80
	createImg( "PlayerImg",
		{ { 15, 0 }, { 30,13 }, { 30,40 }, { 20,40 }, { 20,70 }, { 30,70 }, { 30,80 }, { 0,80 }, { 0,70 }, { 10,70 }, { 10,40 }, { 0,40 }, { 0,13 } },
		0xAA88AA, 0x0022FF, true);

	createImg( "TestBowImg",
		{ { 0, 0 }, { 16,16 }, { 0,31 } },
		0xCCEEAA, 0x000000, false);

	createImg( "TestArrowImg",
		{ {0, 13}, {32, 13}, {32, 0}, {48, 14}, {32, 27}, {32, 15}, {0, 15} },
	0xFF00FF, 0x00FF00, true);

	createImg("TestPlatformImg", 
		{ {0, 0}, {32, 0}, { 32, 16}, {0, 16} },
	0x0000FF, 0x000000, true);

}

IMAGE* ResourcesManager::getImage(std::string strImgName) const
{
	auto pAns = m_vecImgResources.find(strImgName);
	if (pAns != m_vecImgResources.end())
	{
		return pAns->second;
	}
	return nullptr;
}

Atlas* ResourcesManager::getAtlas(std::string strAtlasName) const
{
	auto pAns = m_vecAtlasResources.find(strAtlasName);
	if (pAns != m_vecAtlasResources.end())
	{
		return pAns->second;
	}
	return nullptr;
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
