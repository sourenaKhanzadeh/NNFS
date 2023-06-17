//
// Created by sourena khanzadeh on 2023-06-17.
//

#include "NNFS/DenseLayer.hpp"

Eigen::MatrixXd DenseLayer::forward(const Eigen::MatrixXd& input) {
    this->input = input;
    output = input * weights + biases;
    return activationFunction(output);
}