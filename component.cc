#include <iostream>
#include <stdio.h>
#include"entity.hh"
#include"component.hh"


    Component* Component::clone()
    {
        return new Component(*this);
    }
    bool Component::compare_to(IComparable &other)
    {
        Component& otherCircle = dynamic_cast<Component&> (other);
        return this->get_id() == otherCircle.get_id();

    }

    
    void Component::print() 
    {
        std::cout<<"this is a Component (with id=" +get_id();
        std::cout<<")\n";

    }



    int Component::get_id()
    {
        return id;
    }

    Entity* Component::get_owner()
    {
        return Owner;

    }

    void Component::set_owner( Entity* Owner)
    {
        this->Owner = Owner;
    }