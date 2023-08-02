#include <iostream>
#include "log.h"
#include "Person.h"
using namespace std;

int main(){

    InitLog();
    Log("Hello World");
    Person theBest("Filip", 18);
    Person a = Person("Johan", 57);
    Person b = Person("Lene", 50);
    theBest.addParents(&a, &b);

    theBest.introduce();
    theBest.birthday();

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