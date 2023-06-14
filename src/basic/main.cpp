//
// Created by sourena khanzadeh on 2023-06-13.
//


#include <iostream>
#include "NumCpp.hpp"

int main() {
    nc::NdArray<int> a = {1, 2, 3};
    std::cout << a << std::endl;
    nc::NdArray<int> b = {4, 5, 6};
    std::cout << b << std::endl;

    std::cout << a + b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << nc::dot(a, b) << std::endl;
    return 0;
}