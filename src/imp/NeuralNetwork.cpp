//
// Created by sourena khanzadeh on 2023-06-17.
//

#include "NNFS/NeuralNetwork.hpp"

void NeuralNetwork::addLayer(DenseLayer layer) {
    layers.push_back(layer);
}

Eigen::MatrixXd NeuralNetwork::forward(const Eigen::MatrixXd& input) {
    Eigen::MatrixXd layerOutput = input;
    for (auto& layer : layers) {
        layerOutput = layer.forward(layerOutput);
    }
    return layerOutput;
}

void NeuralNetwork::backpropagation(const Eigen::MatrixXd& input, const Eigen::MatrixXd& target) {
    Eigen::MatrixXd output = forward(input);
    Eigen::MatrixXd error = target - output;

    for (int i = layers.size() - 1; i >= 0; --i) {
        auto& layer = layers[i];
        Eigen::MatrixXd dZ = error.array() * layer.activationFunction.derivative(layer.output).array();
        Eigen::MatrixXd dW = layer.input.transpose() * dZ;
        Eigen::MatrixXd dB = dZ;

        error = dZ * layer.weights.transpose();

        layer.weights += lr * dW;
        layer.biases += lr * dB;
    }
}