#pragma once
#include <easyx.h>
#include <vector>
class Atlas {
public:
	Atlas(std::vector<IMAGE*> vecImgs);
	~Atlas();
	IMAGE* at(int index);
	size_t getSize(); 
	const std::vector<IMAGE*>& getImgs() const;
private:
	std::vector<IMAGE*> m_vecImgs;
};