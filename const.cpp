#include <iostream>
#include <utility>

class Entity{
    private:
        int x = 5;
        int y;
        // allows the var to be edited even within a const function
        mutable int temp;
    public:
        // states that this function will not modify any values
        std::pair<int, int> getCoords() const {
            temp = 5; // temp is mutable, therefore can still be modified
            return std::make_pair(x, y);
        }
};

// As this entity parameter is declared as constant, it will only call
// functions that surely do not modify the entity
int getEntX(const Entity &entity){
    return entity.getCoords().first;
}

int main(){

    const int x = 5;
    // x = 3; => compiler throws error
    
    const int* a = new int;
    // *a = 2; cannot redefine value stored at address
    // however, can reassign address
    a = &x;

    int* const b = new int;
    *b = 2;
    // b = &x; now ptr cannot be changed

    // ! const keeps whatever is to the left of it constant by defualt

    Entity e1;
    std::cout << getEntX(e1) << std::endl;
}