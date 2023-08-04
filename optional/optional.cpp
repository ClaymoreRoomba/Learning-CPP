/* If data may exist
eg: what if a file cannot be read */
#include <iostream>
#include <fstream>
#include <string>
#include <optional>

typedef std::string String;

String badFileToString(const String& filePath) {
    std::ifstream stream(filePath);
    
    if(stream) {
        String res;
        // read file
        stream.close();
        return res;
    } else
        return String(); // same as return ""
}

std::optional<String> goodFileToString(const String& filePath) {
    std::ifstream stream(filePath);
        
    if(stream) {
        String res;
        String line;
        while(std::getline(stream, line)) {
            res.append(line);
            res.append(" ");
        }
        stream.close();
        return res;
    } else
        return {};
}

int main(){
    /* Would have to do something like this:
    String data = badFileToString("data.txt");
    if(data != "") {
      ...  
    }*/

    std::optional<String> data = goodFileToString("data.txt");
    // can also just write if(data) { ...
    if(data.has_value()) {
        std::cout << "File read successfully!\n";
    } else {
        std::cout << "File not accessable :(\n";
    }

    String value = data.value_or("default data");
    std::cout << "Stored data: " << value << std::endl;

    std::cin.get();
    return 0;
}