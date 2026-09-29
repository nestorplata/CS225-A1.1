
#include<iostream>
#include<stdio.h>
#include<list>

class Entity :public IComparable, ICloneable, IPrintable
{
protected:
std::list<Component*> ComponentList;

public:

int component_count();
void attach(Component*);
void attach(Component&);
Component*  operator[] (int);

~Entity();

};

