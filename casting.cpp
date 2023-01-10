#include <iostream>

class Entity {
    private:
    std::string name;
    public:
    Entity(std::string _name) : name(_name) {}
    std::string GetName() { return name; }
};

class Base{
    public:
    Base(){}
    virtual ~Base(){}
};
class Derived : public Base{
    public:
    Derived(){}
    ~Derived(){}
};
class AnotherClass : public Base{
    public:
    AnotherClass(){}
    ~AnotherClass(){}
};


int main(){

    // THE C WAY
    int a = 5;
    // implicit cast (also works the other way around) 
    float b = a;

    // although implicit, it can also be enforced
    float c = 5.25f;
    int d = (int)c;


    // THE C++ WAY
    int s = static_cast<int>(c + 5.5);
    std::cout << s << std::endl;

    std::string animal = "sheep";
    // cannot static_cast this into an entity, however:
    Entity* thing = reinterpret_cast<Entity*>(&animal);
    std::cout << thing->GetName() << std::endl;
    
    // -----------------

    Derived* derived = new Derived();
    // cast derived to a Base
    Base* base = derived;
    
    //assume you don't know if var 'base' is of type Derived or AnotherClass
    AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
    std::cout << ac << ", base is " << (ac ? "" : "not") << " an AnotherClass obj" << std::endl;
    Derived* isDerived = dynamic_cast<Derived*>(base);
    std::cout << isDerived << ", base is " << (isDerived ? "" : "not") << " a Derived obj" << std::endl;
}