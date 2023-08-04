#include <iostream>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    /* 
    Could just have, float x, y, z, w, however:
    All data takes up the same memory:
    floats: [x, y][z, w]
    Vect2s: [  a ][  b ]
    therefore a is essentialy *(Vector2*)(&x)
    */

    union
    {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a;
            Vector2 b;
        };
    };
    
};

void printVec2D(const Vector2& v) {
    std::cout << v.x << " " << v.y << std::endl;
}

int main(){
    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    printVec2D(vector.a);
    printVec2D(vector.b);
    std::cout << "============\n";
    vector.z = 50.0f;
    printVec2D(vector.a);
    printVec2D(vector.b);

    std::cin.get();
    return 0;
}