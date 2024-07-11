#include <iostream>

// this object is an interface, only contains unimplemented methods
class Printable{
    public:
    // considered a "pure virtual function"
    virtual std::string GetClassName() = 0;

};

class Entity : public Printable {
    public:
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }

};

class Player : public Entity {
    private:
    std::string name;
    public:
    Player(std::string _name) : name(_name) {}

    std::string GetName() override { return name; }
    std::string GetClassName() override { return "Player"; }
};

void printName(Entity* entity){
    std::cout << entity->GetName() << std::endl;
}

void printClass(Printable* obj){
    std::cout << obj->GetClassName() << std::endl;
}

int main(){

    // can only instantiate a class inheriting Printable if it defines the function
    Entity* entity = new Entity;
    Player* kris = new Player("Kriswiththatk");

    printClass(entity);
    printClass(kris);

}