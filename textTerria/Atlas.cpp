#include "Atlas.h"
#include "UTIL.hpp"
Atlas::Atlas(std::vector<IMAGE*> vecImgs) : m_vecImgs(vecImgs)
{
}

Atlas::~Atlas()
{
	clearVec(m_vecImgs);
}

IMAGE* Atlas::at(int index)
{
	return m_vecImgs[index];
}

int Atlas::getSize()
{
	return m_vecImgs.size();
}

const std::vector<IMAGE*>& Atlas::getImgs() const
{
	return m_vecImgs;
}
