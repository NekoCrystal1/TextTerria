#pragma once
#include "TObject.h"

class TComponentObject : public TObject
{
public:
	TComponentObject(Transform* pTransform);
	virtual ~TComponentObject() = default;
};
	