#include <iostream>
#include "log.h"
using namespace std;

int main(){

    InitLog();
    Log("Hello World");
    cin.get();
}
/*
    Compile both files:
        g++ main.cpp log.cpp [-o ___]
        ./a.out
    or
        g++ -c main.cpp
        g++ -c log.cpp
        g++ main.o log.o
        ./a.out
*/