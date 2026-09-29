#pragma once

#include<iostream>
#include<stdio.h>
#include<list>

class Component;

class Entity 
{
protected:
std::list<Component*> ComponentList;

public:
Entity() {}

int component_count()
{
    return 0;
}

void attach(Component* p_child)
{
    ComponentList.push_back(p_child);
}

void attach(Component& ref_child)
{
    ComponentList.push_back(&ref_child);
}


Component& Entity::operator[] (int index)
{
    std::list<Component*>::iterator it;
    
    int i =0;
    for (it = ComponentList.begin();it != ComponentList.end(); it++)
    {
        if(i==index) return **it;
        i++;
    }
    return **it;
}


};

