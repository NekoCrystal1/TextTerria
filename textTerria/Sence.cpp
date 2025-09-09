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
	sence_objects.erase(std::remove_if(sence_objects.begin(), sence_objects.end(), [](const TObject* obj){
		bool deletable = obj->get_is_can_delete();
		if (deletable)
			delete obj;
		return deletable;
		}), sence_objects.end());
	for (TObject* i : sence_objects)
		i->on_update();
}

void Sence::on_render() const
{
	for (TObject* i : sence_objects)
		i->on_render();
}

const std::vector<TObject*>& Sence::get_object_set() const
{
	return this->sence_objects;
}

void Sence::push_element(TObject* obj)
{
	sence_objects.push_back(obj);
}

