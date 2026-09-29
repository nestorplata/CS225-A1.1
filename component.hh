#include<stdio.h>
#include<iostream>

class ICloneable
{
    public:
    virtual ICloneable* clone() =0 ;
    ICloneable* operator=(ICloneable &other) {
        return static_cast<ICloneable*>(other.clone());
    }

      ICloneable* operator=(ICloneable *&other) {
        return static_cast<ICloneable*>(other->clone());
    }


};

class IComparable
{
    public:
    virtual bool compare_to(IComparable &other) =0 ;
    bool operator==(IComparable &other) {
        return compare_to(other); // Delegates the comparison to the virtual function
    }
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
    Component(int i = 0) { id  = i; }

    int get_id();
    Component* clone() override;
    bool compare_to(IComparable &other) override;
    void print() override;

    Entity* get_owner();
    void set_owner(Entity* Owner);

    Component* operator=(Component &other) {
        return static_cast<Component*>(other.clone());
    }

      Component* operator=(Component *&other) {
        return static_cast<Component*>(other->clone());
    }

};

