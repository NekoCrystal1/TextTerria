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
	virtual const Transform* get_transform()const;
	virtual void set_position(const Vector2& position);
	virtual void set_position(float x, float y);
protected:
	Transform* m_Transform;
};