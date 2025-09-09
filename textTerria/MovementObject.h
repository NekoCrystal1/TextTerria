#pragma once
#include "TObject.h"
class MovementObject : virtual public TObject {
protected:
	MovementObject();
	~MovementObject();
public:
	virtual void on_update();
	virtual void on_render()const = 0;
	void set_velocity(const Vector2& velocity);
	void set_velocity(float x, float y);
	void set_velocity_x(float x);
	void set_velocity_y(float y);
	void set_max_velocity(const Vector2& max_vec);
	void set_fx(float fx);
	void set_gravity(float g);
	const Vector2& get_velocity()const;
protected:
	Vector2 velocity;
	Vector2 max_velocity;
	Vector2 acceleration;
	float fx_acceleration;
	float gravity;
	bool is_free_fall_heighest_y;
};