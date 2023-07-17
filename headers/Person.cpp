#include "Person.h"
#include <iostream>

Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
}

void Person::birthday() {
    std::cout << "Happy Birthday " << name << "!\n";
    age++;
    std::cout << "You are now " << age << " years old!\n";
}

void Person::introduce() {
    std::cout << "Hi, my name is " << name <<
    " and I am " << age << " years old.\n";

    if(!parents[0]) return;
    std::cout << "My parents are: " << parents[0]->name
    << ", and " << parents[1]->name << std::endl;
}

void Person::addParents(Person* p1, Person* p2) {
    if(!p1 || !p2) {
        std::cout << "Not enough parents provided\n";
        return;
    }

    parents[0] = p1;
    parents[1] = p2;
}