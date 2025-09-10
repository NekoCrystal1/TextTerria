#include "Sence.h"

Sence::Sence()
{
}

Sence::~Sence()
{
	for (TObject* i : sence_objects)
		delete i;
	sence_objects.clear();
}

void Sence::on_update()
{
	sence_objects.erase(std::remove_if(sence_objects.begin(), sence_objects.end(), [](const TEntityObject* obj){
		bool deletable = obj->IsCanBeDeleted();
		if (deletable)
			delete obj;
		return deletable;
		}), sence_objects.end());
	for (TEntityObject* i : sence_objects)
		i->on_update();
}

void Sence::on_render() const
{
	//for (TEntityObject* i : sence_objects)
	//	i->on_render();
}

const std::vector<TEntityObject*>& Sence::get_object_set() const
{
	return this->sence_objects;
}

void Sence::push_element(TEntityObject* obj)
{
	sence_objects.push_back(obj);
}

