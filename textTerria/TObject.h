#pragma once
#include "Transform.h"
#include "Camera.h"
class TObject {
public:
	TObject(const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool is_visiable = false);
	TObject(Transform* transform,bool is_visiable = false);
	virtual ~TObject();
	virtual void on_update() = 0;
	virtual void on_render()const = 0;
	virtual const Transform* get_transform()const;
	virtual void set_visiable(bool is_visiable = true);
	virtual void set_position(const Vector2& position);
	virtual void set_position(float x, float y);
	bool get_is_can_delete() const;
protected:
	Transform* transform;
	bool is_visiable;
	//对象是否还在生命周期中，若不在将被释放
	bool can_delete;
};