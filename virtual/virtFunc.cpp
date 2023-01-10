#include <iostream>

class Entity {
    public:
    virtual std::string GetName(){
        return "Entity";
    }
};

class Player : public Entity{
    private:
    std::string name;
    public:
    std::string GetName() override { return name; }
    Player(std::string _name) : name(_name) {}
};

void printName(Entity* entity){
    std::cout << entity->GetName() << std::endl;
}

int main(){

    Entity* entity = new Entity;
    Player* player = new Player("NicoNicoNEEE");

    printName(entity);
    // Without virtual, printName(player) would print "Entity"
    // Virtual deprioritizes the function
    printName(player);

}