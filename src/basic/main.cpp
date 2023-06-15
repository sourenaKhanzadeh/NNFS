//
// Created by sourena khanzadeh on 2023-06-13.
//


#include <iostream>
#include "NumCpp.hpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

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
    plt::plot({1,3,2,4});
    plt::show();
    return 0;
}