//
// Created by sourena khanzadeh on 2023-06-17.
//

#ifndef NNFS_DENSELAYER_HPP
#define NNFS_DENSELAYER_HPP

#include "Eigen/Dense"
#include "ActivationFunction.hpp"

class DenseLayer {
public:
    Eigen::MatrixXd weights;
    Eigen::MatrixXd biases;
    Eigen::MatrixXd output;
    Eigen::MatrixXd input;
    ActivationFunction& activationFunction;

    DenseLayer(int inputSize, int outputSize, ActivationFunction& activationFunction)
            : activationFunction(activationFunction) {
        weights = Eigen::MatrixXd::Random(inputSize, outputSize);
        biases = Eigen::MatrixXd::Random(1, outputSize);
    }

    Eigen::MatrixXd forward(const Eigen::MatrixXd& input);
};

#endif //NNFS_DENSELAYER_HPP
