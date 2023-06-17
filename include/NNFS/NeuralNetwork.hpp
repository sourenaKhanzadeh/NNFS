//
// Created by sourena khanzadeh on 2023-06-17.
//

#ifndef NNFS_NEURALNETWORK_HPP
#define NNFS_NEURALNETWORK_HPP

#include <vector>
#include "DenseLayer.hpp"

class NeuralNetwork {
private:
    double lr;
    std::vector<DenseLayer> layers;
public:
    NeuralNetwork(double lr=0.1): lr(lr) {}

    void addLayer(DenseLayer layer);

    Eigen::MatrixXd forward(const Eigen::MatrixXd& input);

    void backpropagation(const Eigen::MatrixXd& input, const Eigen::MatrixXd& target);
};


#endif //NNFS_NEURALNETWORK_HPP
