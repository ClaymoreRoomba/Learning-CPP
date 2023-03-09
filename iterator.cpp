// iterators are basically ptrs to elements in an array
// for extra info see: https://www.geeksforgeeks.org/introduction-iterators-c/

#include <iostream>
#include <vector>

int main()
{
    // Declaring a vector
    std::vector<int> v = { 1, 2, 3, 4, 5 };
 
    std::cout << "Without iterators = ";
     
    // Accessing the elements without using iterators
    for (int j = 0; j < v.size(); ++j)
    {
        std::cout << v[j] << " ";
    }
 
    std::cout << "\nWith iterators = ";
     
    // Accessing the elements using iterators
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }  

    std::vector<int>::iterator i = v.begin();
    advance(i, 3); // increments by 3 elements, now points to element 4 (index 0 --> 3)

    std::vector<int>::iterator ptr = v.begin();
    std::vector<int>::iterator ftr = v.end();

        std::cout << "\nbegin(): " << *ptr << ", end(): " << *ftr << ", advanced: " << *i << "\n";

    auto it = next(ptr, 2); // return new iterator if it had advanced by 2
    auto it1 = prev(ftr, 2); // return new iterator if it had decremented by 2

    std::cout << "next: " << *it << ", prev: " << *it1 << "\n";



    std::vector<int> ar1 = {10, 20, 30}; 
      
    // copying 1 vector elements in other using inserter()
    // inserts ar1 after 3rd position in ar
    std::copy(ar1.begin(), ar1.end(), std::inserter(v,i));
      
    // Displaying new vector elements
    std::cout << "The new vector after inserting elements is : ";
    for (int &x : v) 
        std::cout << x << " ";

}