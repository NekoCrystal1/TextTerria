#pragma once
#include "TObject.h"
class TComponentObejct : public TObject
{
public:
	TComponentObejct();
	~TComponentObejct();
protected:
	const Transform*  m_pParentTransform;
};