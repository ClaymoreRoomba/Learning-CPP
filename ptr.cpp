#include <iostream>

class Entity {
    private:
    std::string name;

    public:

    Entity(std::string _name) : name(_name) {};

    std::string getName(){
        return name;
    }

};

// retains address, uses the actual variable, does not make a copy
void passby(int& x){
    x++;
}

// could also take an address as argument and dereference
void passby(int* x){
    (*x)++;
}



int main(){

int x = 0;
passby(x);
std::cout << "x: " << x << std::endl;

// make a pointer storing the address of x
int* ptr = &x;
passby(ptr);
std::cout << "x: " << x << std::endl;

Entity* ePtr = new Entity("Player1");

// std::cout << (*ePtr).getName() << std::endl;
std::cout << ePtr->getName() << std::endl;
    
const int* a = new int;
// *a = 2; cannot redefine value stored at address
// however, can reassign address
a = &x;

int* const b = new int;
*b = 2;
// b = &x; now ptr cannot be changed

}