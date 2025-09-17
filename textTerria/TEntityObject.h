#pragma once
#include "TNodeInterface.hpp"
#include "TWorldTransformObject.h"
class TEntityObject : public TWorldTransformObject, public TNodeInterface<TEntityObject>
{
	friend TComponentObject;
	defaultSetParent(TEntityObject);
	defaultRemoveNextNodesTo(TEntityObject);
	defaultChangeNextNodeParent(TEntityObject);
	defaultWorldTransformVirtualFuncInNode;
private:
	TEntityObject(const TEntityObject& t) = delete;
public:
	TEntityObject(TEntityObject* pParent, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	TEntityObject(TEntityObject* pParent, const Transform& transform = Transform());
	virtual ~TEntityObject();
public:
	virtual void on_update();
	void setCanBeDeleted(bool bValue = true);
	bool IsCanBeDeleted() const;
protected:
	bool m_bIsCanBeDeleted;
};
