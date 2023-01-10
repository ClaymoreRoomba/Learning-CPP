#include <iostream>

class Entity {

    public:
    Entity() { std::cout << "An entity was created\n"; }
    ~Entity() { std::cout << "An entity was destroyed\n"; }

};

class Player : public Entity {
    private:
    std::string name;
    
    public:
    Player(std::string _name) : name(_name) { std::cout << "Player " << name << " was created\n"; }
    ~Player() { std::cout << name << " was destroyed\n"; }

};


class Base {

    public:
    Base() { std::cout << "An entity was created\n"; }
    // ensures lower priority
    virtual ~Base() { std::cout << "An entity was destroyed\n"; }

};

class Derived : public Base {
    private:
    int* m_Array;

    public:
    Derived() { m_Array = new int[5]; std::cout << "Derived constructor\n"; }
    // derived constructor should be called in order to avoid memory leak (the array)
    ~Derived() { delete[] m_Array; std::cout << "Derived destructor\n"; }

};



int main(){

    Entity* entity = new Entity(); // 1. Entity constructor
    delete entity; // 2. Entity destructor
    std::cout << "--------------\n";
    Player* p1 = new Player("Kris"); // 1a. Entity constructor, 1b. Player constructor
    delete p1; // 2a. Player destructor, 2b. Entity destructor
    std::cout << "--------------\n";
    Entity* npc = new Player("Harold"); // 1a. Entity constructor, 1b. Player constructor
    delete npc; // 2a. Entity destructor, 2b. ______ (Entity data already deleted)

    std::cout << std::endl;

    Base* base = new Base(); // 1. Base constructor
    delete base; // 2. Base destructor
    std::cout << "--------------\n";
    Derived* derived = new Derived(); // 1a. Base constructor, 1b. Derived constructor
    delete derived; // 2a. Derived destructor, 2b. Base destructor
    std::cout << "--------------\n";
    Base* poly = new Derived(); // 1a. Base constructor, 1b. Derived constructor
    delete poly; // 2a. Derived destructor, 2b. Base destructor

    std::cin.get();
}