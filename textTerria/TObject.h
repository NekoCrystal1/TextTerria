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
	virtual void setLocalPosition(const Vector2& position);
	virtual void setLocalPosition(float x, float y);
	virtual void setLocalAnchor(const Vector2& oNewAnchor);
protected:
	//尽量使用虚函数setLocal...来修改，这样才能影响子节点、组件等；如果要直接修改请确保不需要影响组件
	Transform* m_pLocalTransform;
};