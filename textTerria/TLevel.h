#pragma once
#include "TEntityObject.h"
class TLevel : public TEntityObject
{
public:
	TLevel();
	~TLevel();
public:
	virtual void on_update() override;
protected:
	std::vector<TEntityObject> m_vecUpdateNodes;
};