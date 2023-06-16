//
// Created by sourena khanzadeh on 2023-06-16.
//

#ifndef NNFS_NEURON_HPP
#define NNFS_NEURON_HPP

#include "NumCpp.hpp"

class Neuron {
public:
    Neuron(bool isInput, int inputSize, int outputSize);
    ~Neuron();
    void updateWeights();

private:
    nc::NdArray<double> inputs;
    nc::NdArray<double> weights;
    double bias;
    double output;
    bool isInput;
    int inputSize;
    int outputSize;
    double learningRate;
    double error;
    double delta;
};

#endif //NNFS_NEURON_HPP
