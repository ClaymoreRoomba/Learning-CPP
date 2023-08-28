#include <iostream>
#include <vector>
#include <functional>

// Return values
float sum(float x, float y) { return x + y; }

// Can provide default args
void print(float x, float y = 5)
{
    std::cout << "x is " << x << ", and y is: " << y << std::endl;
}
// same name, but will decide which fn to call based on arguments
void print(std::string str)
{
    std::cout << str << std::endl;
}

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int value : values)
        func(value);
}

int main(){
    // * Function pointers
    auto function = &HelloWorld;
    function();

    // This syntax is confusing
    float (*sumFn)(float, float); // = sum
    sumFn = sum;
    print(2.1f, 3.5f);
    std::cout << "The sum is: " << sumFn(2.1f, 3.5f) << std::endl;
    // Therefore can do this instead:
    typedef void(*PrintFunction)(std::string);
    PrintFunction printFn = print;
    printFn("Printing using function pointers!\n");

    std::vector<int> values = { 1, 5, 4, 2, 3 };
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });

    // Using <functional> lib:
    std::function<float(float, float)> Product = [](float v1, float v2) -> float
    {
        return v1 * v2;
    };

    std::cout << "The product of 2.2 and 5.5 is: " << Product(2.2f, 5.5f) << std::endl;
}