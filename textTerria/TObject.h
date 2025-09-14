#pragma once
#include "Transform.h"
class TComponentObject;
class TObject
{
	friend TComponentObject;
private:
	TObject(const TObject& t) = delete;
public:
	TObject(Transform* transform);
	virtual ~TObject() = default;
	//获取本地变化指针;
	virtual const Transform* getTransform()const;
	virtual const Transform& gerLocalTransform() const;
	virtual void set_position(const Vector2& position);
	virtual void set_position(float x, float y);
protected:
	Transform* m_pLocalTransform;
};