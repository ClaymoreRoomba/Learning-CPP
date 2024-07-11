#include <iostream>
#include <string>
#include <variant>
typedef std::string String;

enum class ErrorCode {
    None, NotFound, NoAccess
};

std::variant <String, ErrorCode> FileToString() {
    // Just an example function
    // Now could return either a String or ErrorCode
    return {};
}

int main(){
    std::variant<String, int> foo;
    foo = "string";
    std::cout << std::get<String>(foo) << "\nindex: " << foo.index() << "\n\n";
    foo = 2;
    std::cout << std::get<int>(foo) << "\nindex: " << foo.index() << "\n\n";

    // can check type of variable using foo.index(), or:
    // will return nullptr if not correct type
    if(auto value = std::get_if<std::string>(&foo)) {
        // Do shit
    }

    std::cin.get();
    return 0;
}