#include <iostream>
#include <memory>

class Entity {
private:
public:
    Entity() {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity() {
        std::cout << "Destroyed Entity!" << std::endl;
    }
    void seeWazGud(size_t num) {
        std::cout << "WazGud #" << num << std::endl;
    }
};

int main(){

    // * Unique pointer
    {
        /* Now just have a scoped pointer,
        memory will be freed when leaving scope 'entity' was made in */
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->seeWazGud(1);
        /* std::unique_ptr<Entity> e0 = entity; 
        cannot copy, as soon as entity dies, so does the object stored at that ptr
        therefore no reason to ever copy
        (see shared ptr) */
    }
 

    // * Shared pointer
    {
        // Uses reference counting
        std::shared_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
        }
        // still 1 reference to memory (e0), therefore object still exists
        e0->seeWazGud(2);
    }
    // Object stored at memory sharedEntity is only now deleted

    // * Weak pointer
    {
        // Does not increase reference count of shared_ptr
        std::weak_ptr<Entity> e1;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e1 = sharedEntity;
        }
        // as e1 does not increase reference count, object at sharedEntity is now gone
        std::cout <<
        (e1.expired() ? 
        "e1's memory has been freed" :
        "object still exists at e1's memory") <<
        std::endl; 
    }

    std::cin.get();
    return 0;
}