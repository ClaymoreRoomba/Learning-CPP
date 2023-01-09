#include <iostream>
#include "log.h"

void Log(std::string message){
    std::cout << message << std::endl;
}

void InitLog(){
    Log("Initializing Log");
}