#include <iostream>

int main(int argc, char** argv) {
    std::cout << "You have entered " << argc - 1 << " arguments:\n";
    
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }
}