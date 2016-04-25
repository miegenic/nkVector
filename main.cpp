#include <iostream>
#include "nkVector.h"

int main() {
    nkVector vektors; // Create new vector
    for(int i = 0; i <= 50; i++) {
        vektors.push_back(i); // Push in elements
    }

    std::cout << "=== CURRENT VALUES ===" << std::endl;
    for(int i = vektors.begin; i < vektors.end; i++) { // iterate over the vector
        std::cout << vektors[i] << " "; // print out the values
    }
    std::cout << "\n" << "VECTOR SIZE: " << vektors.vSize() << std::endl;
    std::cout << "VECTOR MAX SIZE: " << vektors.vMax() << std::endl;

    vektors.deleteLast(); // Delete last value
    std::cout << std::endl << "vector.deleteLast() " << std::endl;
    for(int i = vektors.begin; i < vektors.end; i++) {
        std::cout << vektors[i] << " ";
    }
    std::cout << "\n" << "VECTOR SIZE: " << vektors.vSize() << std::endl;
    std::cout << "VECTOR MAX SIZE: " << vektors.vMax() << std::endl;

    vektors.deleteFirst(); // Delete first value
    std::cout << std::endl << "vector.deleteFirst() " << std::endl;
    for(int i = vektors.begin; i < vektors.end; i++) {
        std::cout << vektors[i] << " ";
    }
    std::cout << "\n" << "VECTOR SIZE: " << vektors.vSize() << std::endl;
    std::cout << "VECTOR MAX SIZE: " << vektors.vMax() << std::endl;

    vektors.changeMaximum(50);
    std::cout << std::endl << "vector.changeMaximum(50); " << std::endl;
    for(int i = vektors.begin; i < vektors.end; i++) {
        std::cout << vektors[i] << " ";
    }
    std::cout << "\n" << "VECTOR SIZE: " << vektors.vSize() << std::endl;
    std::cout << "VECTOR MAX SIZE: " << vektors.vMax() << std::endl;

    vektors.changeMultiplier(10);
    for(int i = 0; i <= 100; i++) {
        vektors >> i;
    }
    std::cout << std::endl << "vector.changeMultiplier(10) " << std::endl;
    for(int i = vektors.begin; i < vektors.end; i++) {
        std::cout << vektors[i] << " ";
    }
    std::cout << "\n" << "VECTOR SIZE: " << vektors.vSize() << std::endl;
    std::cout << "VECTOR MAX SIZE: " << vektors.vMax() << std::endl;
}