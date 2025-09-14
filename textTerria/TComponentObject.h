#pragma once
#include "TEntityObject.h"

class TComponentObject : public TObject
{
public:
	TComponentObject(TEntityObject* pParent);
	virtual ~TComponentObject() = default;
	virtual const Transform& getWorldTransform();
public:
	TEntityObject* getParent() const;
protected:
	TEntityObject* m_pParent;
};
	