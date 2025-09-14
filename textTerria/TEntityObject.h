#pragma once
#include "TObject.h"
#include "TNodeInterface.hpp"
class TEntityObject : public TObject, TNodeInterface<TEntityObject>
{
	friend TComponentObject;
private:
	TEntityObject(const TEntityObject& t) = delete;
public:
	TEntityObject(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	TEntityObject(const Transform& transform = Transform());
	virtual ~TEntityObject();
public:
	virtual void on_update();
	void setCanBeDeleted(bool bValue = true);
	bool IsCanBeDeleted() const;
	const Transform& getWorldTransform();
protected:
	void updateTransform();
	void makeDirty();
protected:
	bool m_bIsCanBeDeleted;
	//父节点及自身改变会导致世界坐标需要更新，在get时更新
	bool m_bIsTransformDirty;
	Transform* m_pWorldTransform;
};