#pragma once
#include <easyx.h>
#include <vector>
#include "Camera.h"
#include "TEntityObject.h"
class Sence {
public:
	Sence() = default;
	virtual ~Sence() = default;
	virtual void on_update() = 0;
	virtual void on_render()const = 0;
	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
};