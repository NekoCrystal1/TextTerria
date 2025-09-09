#pragma once
#include "Actor.h"
class ActorManager {
private:
	static ActorManager* manager;
public:
	static ActorManager* instance();
public:

private:
	ActorManager();
	~ActorManager();
private:

};