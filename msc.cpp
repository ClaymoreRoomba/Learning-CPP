#include <iostream>
#include <vector>

template <typename T>
void printVec(std::vector<T> list){
    std::cout << "Func List address: " << &list << '\n';
    for(T el : list) {
        std::cout << el << ", ";
    }
}

int main(){
    std::vector<int>* nums = new std::vector<int>{3, 4, 5, 2, 1};
    std::cout << "Main list address: " << nums << '\n';
    printVec(*nums);
}