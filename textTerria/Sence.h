#pragma once
#include <easyx.h>
#include <vector>
#include "Camera.h"
#include "TEntityObject.h"
class Sence {
public:
	Sence();
	virtual ~Sence();
	virtual void on_update();
	virtual void on_render()const;
	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
	const std::vector<TEntityObject*>& get_object_set()const;
	void push_element(TEntityObject* obj);
protected:
	std::vector<TEntityObject*> sence_objects;
};