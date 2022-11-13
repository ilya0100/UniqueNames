#include <iostream>
#include "names_holder.h"

#define CREATE 1
#define RENAME 2
#define ERASE 3
#define GET 4
#define EXIT 5


void print_options() {
    std::cout << "Choose option:" << std::endl;
    std::cout << "1: Create new name" << std::endl;
    std::cout << "2: Rename" << std::endl;
    std::cout << "3: Erase name" << std::endl;
    std::cout << "4: Get name" << std::endl;
    std::cout << "5: Exit" << std::endl;
}

int main() {
    NamesHolder names;

    #ifdef NDEBUG
        print_options();
    #endif
    
    bool close_app = false;
    while (!close_app) {
        int command = 0;
        std::cin >> command;

        switch (command) {
        case CREATE:
            std::cout << names.create() << std::endl;
            break;

        case RENAME: {
            std::string new_name;
            std::size_t id = 0;

            std::cin >> id >> new_name;
            if (!names.rename(id, new_name))
                std::cout << "Name: " << new_name << " already exists" << std::endl;
            break;
        }

        case ERASE: {
            std::size_t id = 0;
            std::cin >> id;
            names.erase(id);
            break;
        }

        case GET: {
            std::size_t id = 0;
            std::cin >> id;
            std::cout << names.get(id) << std::endl;
            break;
        }

        case EXIT:
            close_app = true;
            break;

        default:
            std::cout << "Unknown command" << std::endl;
            #ifdef NDEBUG
                print_options();
            #endif
            break;
        }
    }
    return 0;
}