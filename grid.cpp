#include <iostream>

void printGrid() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

int main() {
    printGrid();
    return 0;
}