#include <iostream>
#include <stdio.h>
#include "component.hh"
#include "entity.hh"




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


Entity::~Entity()
{

    
}

