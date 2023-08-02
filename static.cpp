#include <iostream>

void printPseudoRandNum()
{
    // allocates memory that lives 'til end of runtime
    static int c = 0;
    std::cout << c << ' ';
    c++;
}

struct Entity
{
    static int numEntities;
    Entity(){ /* numEntities++; would throw error*/ };
    virtual ~Entity(){};
    int getNumEntities(){ return numEntities; }
};

int main(){
    for(size_t i = 0; i < 5; i++)
        printPseudoRandNum(); // outputs: 0 1 2 3 4

    // c = 10; throws error, cannot be accessed globally

    Entity thing1;
    thing1.numEntities = 1;
    std::cout << thing1.getNumEntities() << '\n';    
    Entity thing2;
    thing2.numEntities = 2;

}