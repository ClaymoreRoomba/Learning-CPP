#include <iostream>
#include <fstream>
#include <future>
#include <string>
#include <vector>
#include <functional>

std::vector<std::future<void>> futures;

class Mesh {
private:
    Mesh(){};
public:
    static Mesh Load(std::string filePath) {
        // Example code to take up time
        for(char& c : filePath) {
            for(int i = 0; i < 1000; i++) {
                c = (char)((c + 1) % 200);
            }
        }
        return Mesh();
    }

    ~Mesh(){};
};

std::vector<Mesh> meshes;
std::mutex meshesMutex;

// make sure string parameter is copied, memory could be cleared before LoadMesh finishes
void LoadMesh (std::vector<Mesh>* meshVector, std::string filePath)
{
    auto mesh = Mesh::Load(filePath);

    // ! Watch out, some things may only be accessable one at a time
    // ! Lock vector, push, unlock
    std::lock_guard<std::mutex> lock(meshesMutex);
    meshVector->push_back(mesh);

    // Will be unlocked when variable lock is destroyed (leaving function)
};

void LoadMeshes() {
    std::ifstream stream("models.txt");
    std::string line;
    std::vector<std::string> meshFilePaths;
    while(std::getline(stream, line)) 
        meshFilePaths.push_back(line);
    

#define ASYNC 1
#if ASYNC
    std::cout << "Asynchronous\n";
    for(const auto& file : meshFilePaths)
    {
        // std::launch async assures multithreading, function to be called
        futures.push_back(std::async(std::launch::async, LoadMesh, &meshes, file));
    }
#else
    std::cout << "Not Asynchronous\n";
    // All meshes do not have to be loaded after each other
    for(const auto& file : meshFilePaths)
        meshes.push_back(Mesh::Load(file));
#endif
}

#include <chrono>

int main(){
    // * async takes around 1000 microseconds
    // * non-async takes around 2500 microseconds

    auto start = std::chrono::high_resolution_clock::now();
    LoadMeshes();
    auto stop = std::chrono::high_resolution_clock::now();
    auto difference = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time Elapsed: " << difference.count() << " microseconds" << std::endl;

    std::cin.get();
    return 0;
}