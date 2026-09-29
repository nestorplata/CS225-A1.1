#pragma once

#include<stdio.h>
#include<iostream>
#include<string>

class ICloneable
{
    public:
    virtual ICloneable* clone() =0 ;



};

class IComparable
{
    public:
    virtual bool compare_to(IComparable &other) =0 ;

};

class IPrintable
{
    public:
    virtual void print() =0 ;
};

class Entity;

class Component :public IPrintable, public ICloneable, public IComparable
{


    public:
    Entity* Owner;
    int id;


    public:
    Component(int i = 0) { id  = i; }
    const int get_id()
    {
        return id;
    }

    ICloneable* clone()
    {
        ICloneable* cloned = new Component(*this);
        return cloned;
    }
    bool compare_to(IComparable &other)
    {
        Component& otherComponent = dynamic_cast<Component&> (other);
        return this->get_id() == otherComponent.get_id();

    }

    void print() 
    {
        std::cout<<"this is a Component (with id=" + std::to_string(this->get_id()) + ")\n";

    }

    Entity* get_owner()
    {
        return Owner;

    }
     void set_owner( Entity* Owner)
    {
        this->Owner = Owner;
    }


};

