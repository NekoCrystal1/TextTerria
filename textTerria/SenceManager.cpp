#include "SenceManager.h"

void SenceManager::on_update()
{
    cur_sence->on_update();
}

void SenceManager::on_render()const
{
    if (!cur_sence)
        return;
    cur_sence->on_render();
}

void SenceManager::switch_to(std::string target)
{
    if (cur_sence)
        cur_sence->on_exit();
    cur_sence = sences[target];
    cur_sence->on_enter();
}

void SenceManager::add_sence(std::string name, Sence* new_sence)
{
    sences.insert({ name,new_sence });
}

void SenceManager::set_cur_sence(Sence* sence)
{
    if (cur_sence)
        cur_sence->on_exit();
    this->cur_sence = sence;
    cur_sence->on_enter();
}

SenceManager::SenceManager() :cur_sence(nullptr),sences()
{
};
 