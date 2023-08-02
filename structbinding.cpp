#include <iostream>
#include <unordered_map>
#include <tuple>

struct Animal {

    std::string species;
    std::string color;

    Animal(std::string _species, std::string _color) : species(_species), color(_color) {};

};

void loop_map_items(){
    
    std::unordered_map<std::string, std::string> colors = {
        {"RED",     "#FF0000"},
        {"GREEN",   "#00FF00"},
        {"BLUE",    "#0000FF"}
    };

    for(const auto&[name, hex] : colors){
        std::cout << "name: " << name << ", hex: " << hex << '\n';
    }
}

std::tuple<std::string, int> CreatePerson(){
    return { "Filip", 18 };
}

int main(){
    loop_map_items();
    
    auto[name, age] = CreatePerson();
    std::cout << name << " is " << age << " years old\n";
    
    auto [species, color] = Animal("Dog", "Gray");
    std::cout << "Firro is a " << color << " " << species << '\n';

}