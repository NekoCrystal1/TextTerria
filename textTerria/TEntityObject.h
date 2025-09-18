#pragma once
#include "TNodeInterface.hpp"
#include "TWorldTransformObject.hpp"

class TEntityObject : public TWorldTransformObject<TEntityObject>, public TNodeInterface<TEntityObject>
{
	friend TComponentObject;
private:
	TEntityObject(const TEntityObject& t) = delete;
public:
	TEntityObject(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	TEntityObject(const Transform& transform);
	virtual ~TEntityObject();
public:
	virtual void on_update();
	void setCanBeDeleted(bool bValue = true);
	bool IsCanBeDeleted() const;
protected:
	bool m_bIsCanBeDeleted;
};
