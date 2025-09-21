#pragma once
#include <easyx.h>
#include "Singleton.hpp"
#include "TEntityObject.h"

#define CAMERA Camera::instance()

class Camera : public TEntityObject, public Singleton<Camera>
{
	friend Singleton<Camera>;
public:
	void on_input(ExMessage& msg);
	void on_uodate();
	bool isShouldRender(const Transform& transform);
	const Vector2& get_centre();
	const Vector2& get_position();
	const Vector2& get_vision_scale();
	Vector2 transformRenderCentre(const Vector2& centre_position);
	Vector2 transformRenderSize(const Vector2& size);
	Transform transformRenderTransform(const Transform& target_transform);

protected:
	virtual void updateTransform()override;
private:
	Camera();
	~Camera() = default;
private:
	bool up = 0, down = 0, left = 0, right = 0,add_scale = 0,sub_scale = 0;
	Vector2 vision_scale;
};
