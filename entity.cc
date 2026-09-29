#include <iostream>
#include <stdio.h>
#include "component.hh"
#include "entity.hh"

int Entity::component_count()
{
    return ComponentList.size();
}

void Entity::attach(Component* p_child)
{
    ComponentList.push_back(p_child);
}

void Entity::attach(Component& ref_child)
{
    ComponentList.push_back(&ref_child);
}

Component* Entity::operator[] (int index)
{

    std::list<Component*>::iterator it;
    
    int i =0;
    for (it = ComponentList.begin();it != ComponentList.end(); it++, i++)
    {
        if(i==index) return *it;
    }
    return nullptr;    
}


Entity::~Entity()
{

    
}

