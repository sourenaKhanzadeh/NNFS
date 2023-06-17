//
// Created by sourena khanzadeh on 2023-06-13.
//


#include <iostream>
#include "NumCpp.hpp"
#include "matplotlibcpp.h"
#include "NNFS/ActivationFunction.hpp"
#include "NNFS/NeuralNetwork.hpp"
#include "NNFS/DenseLayer.hpp"

namespace plt = matplotlibcpp;

int main() {
    Sigmoid sigmoid;
    NeuralNetwork nn(0.1);

    nn.addLayer(DenseLayer(2, 3, sigmoid));
    nn.addLayer(DenseLayer(3, 1, sigmoid));

    Eigen::MatrixXd input(1, 2);
    input << 1.0, 0.5;

    Eigen::MatrixXd target(1, 1);
    target << 0.8;

    Eigen::MatrixXd losses(1, 10000);

    for (int i = 0; i < 10000; ++i) {
        nn.backpropagation(input, target);
        losses(0, i) = (nn.forward(input) - target).array().pow(2).sum();
    }

    Eigen::MatrixXd output = nn.forward(input);
    std::cout << "Output after training: \n" << output << std::endl;

    std::vector<double> x(10000);
    std::vector<double> y(10000);
    std::iota(x.begin(), x.end(), 0);
    std::copy(losses.data(), losses.data() + losses.size(), y.begin());
    plt::title("Loss");
    plt::xlabel("Epoch");
    plt::ylabel("Loss");
    plt::plot(x, y);
    plt::show();


    return 0;
}