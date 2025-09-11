#pragma once
#include "TEntityObject.h"

class TComponentObject : public TObject
{
public:
	TComponentObject(TEntityObject* pParent);
	virtual ~TComponentObject() = default;
protected:
	TEntityObject* m_pParent;
};
	