
#include<iostream>
#include<stdio.h>
#include<list>

class Entity 
{
protected:
std::list<Component*> ComponentList;

public:
 Entity() {}
int component_count();
void attach(Component*);
void attach(Component&);

Component& operator[] (int index);

~Entity();

};

