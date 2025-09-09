#include "ActorManager.h"
ActorManager* ActorManager::manager = nullptr;
ActorManager* ActorManager::instance()
{
	if (!manager)
		manager = new ActorManager();
	return manager;
}

ActorManager::ActorManager()
{
}

ActorManager::~ActorManager()
{
}
