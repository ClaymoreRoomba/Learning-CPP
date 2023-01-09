#include <iostream>

namespace apple{

    void print(std::string message){
        std::cout << "🍎 " << message << std::endl;
    }

    void doSomething(int &x){

        x += 5;

    }
}

namespace orange{

    void print(std::string message){
        std::string temp = message;
        std::reverse(temp.begin(), temp.end());
        std::cout << "🍊 " << temp << std::endl;
    }

    void doSomething(int &x){

        x *= 2;

    }

}

int main(){

    apple::print("Hello World");
    orange::print("Hello World");

    using apple::doSomething;

    int num = 2;
    doSomething(num);
    std::cout << num << std::endl;

    namespace o = orange;
    o::doSomething(num);
    std::cout << num << std::endl;
}