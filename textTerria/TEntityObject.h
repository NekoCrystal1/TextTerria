#pragma once
#include "TNodeInterface.hpp"

class TEntityObject : public TNodeInterface<TEntityObject>
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
	virtual void setLocalPosition(const Vector2& position)override;
	virtual void setLocalPosition(float x, float y)override;
protected:
	bool m_bIsCanBeDeleted;
};
