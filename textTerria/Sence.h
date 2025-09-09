#pragma once
#include <easyx.h>
#include <vector>
#include "Camera.h"
#include "TObject.h"
class Sence {
public:
	Sence();
	virtual ~Sence();
	virtual void on_update();
	virtual void on_render()const;
	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
	const std::vector<TObject*>& get_object_set()const;
	void push_element(TObject* obj);
protected:
	std::vector<TObject*> sence_objects;
};