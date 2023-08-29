#include <iostream>
#include <vector>
#include <algorithm>
// Lambda functions are just anonymous functions

template<typename T>
void printVec(std::vector<T> vec, std::string title = ""){

  std::cout << title << std::endl << "[";
  for(int i = 0; i < vec.size() - 1; i++){
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[vec.size() - 1] << "]\n";

};

int main(){

std::vector<int> vec = {10, 20, 65, 35, 225, 100, 50};
printVec(vec, "Before erase:");

// erase values greater than 100
vec.erase(
// make iterator of list of elements greater than 100
std::remove_if(vec.begin(), vec.end(),
  // anonymous function passed as a parameter
  // takes an element in, returns type bool
  [](int element) -> bool
  {
      return element > 100; 
  }

),
    
vec.end());

printVec(vec, "After erase #1");

int max = 60;

vec.erase(

std::remove_if(vec.begin(), vec.end(),

  // can now read outside variables (max)
  [=](int element) -> bool
  {
    return element > max; 
  }

),
    
vec.end());

printVec(vec, "After erase #2");

vec.erase(

std::remove_if(vec.begin(), vec.end(),
  // can now edit outside variables
  [&](int element) -> bool
  {
    max = 10;
    return element > max; 
  }

),
    
vec.end());

printVec(vec, "After erase #3");

/*

[=] allows access to variables in scope, but cannot modify
[&] allows access to variables in scope, can modify them
[var] allows variable to be used in lambda func
[&var] allows variable to be used and modified in lambda function

*/

}