#pragma once
#include "TNodeInterface.hpp"
#include "TWorldTransformObject.h"
class TEntityObject : public TWorldTransformObject, TNodeInterface<TEntityObject>
{
	friend TComponentObject;
	defaultSetParent(TEntityObject);
	defaultRemoveNextNodesTo(TEntityObject);
	defaultWorldTransformVirtualFuncInNode;
private:
	TEntityObject(const TEntityObject& t) = delete;
public:
	TEntityObject(const Vector2& size = Vector2(), const Vector2& position = Vector2(), TEntityObject* pParent);
	TEntityObject(const Transform& transform = Transform(), TEntityObject* pParent);
	virtual ~TEntityObject();
public:
	virtual void on_update();
	void setCanBeDeleted(bool bValue = true);
	bool IsCanBeDeleted() const;
protected:
	bool m_bIsCanBeDeleted;
};
