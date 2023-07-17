#pragma once
#include <iostream>

class Person {
    private:
    std::string name;
    int age;
    Person* parents[2];

    public:
    Person(std::string name, int age);
    void introduce();
    void birthday();
    void addParents(Person* p1, Person* p2);
};