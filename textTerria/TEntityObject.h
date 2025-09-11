#pragma once
#include "TObject.h"

class TEntityObject : public TObject
{
	friend TComponentObject;
private:
	TEntityObject(const TEntityObject& t) = delete;
public:
	TEntityObject(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	TEntityObject(const Transform& transform = Transform());
	virtual ~TEntityObject();
public:
	virtual void on_update() = 0;
	void setCanBeDeleted(bool bValue = true);
	bool IsCanBeDeleted() const;
protected:
	bool m_bIsCanBeDeleted;
};