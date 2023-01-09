//Templates are just blueprints that allow the compiler to write code for you at runtime
#include <iostream>
using namespace std;

template <typename T>
void printArr(T &arr){
    const int length = sizeof(arr)/sizeof(arr[0]);
    std::cout << "[";
    for(int i = 0; i < length - 1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[length - 1] << "]\n";
}

template <typename T, int N>
class Array{

private:
    T m_array[N];
public:
    int getSize() {return N;}
};

int main(){

    int arr[5] = {1,2,3,4,5};
    printArr(arr);

    //includes the null-character \0, indicating that the string is ended
    printArr("nice");

    Array<float, 5> newArr;
    cout << newArr.getSize() << endl;
}