#include <iostream>

struct Vector2{
    float x, y;

    Vector2(float _x, float _y) : x(_x), y(_y) {};
    virtual ~Vector2(){};

    Vector2 operator+(const Vector2 &other) const {
        return Vector2(x + other.x, y + other.y);
    }

};

//overloading the stream operator, has nothing to do with vector itself
std::ostream& operator<<(std::ostream &stream, Vector2 &vector) {
    stream << "[ " << vector.x << ", " << vector.y << " ]";
    return stream;
}

int main(){
    Vector2 pos(3, 4);
    Vector2 speed (1, 1);

    Vector2 moved = pos + speed;

    std::cout << "Pos: " << pos << '\n';
    std::cout << "Speed: " << speed << '\n';
    std::cout << "Moved: " << moved << '\n';
}