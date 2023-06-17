//
// Created by sourena khanzadeh on 2023-06-16.
//

#ifndef NNFS_ACTIVATIONFUNCTION_HPP
#define NNFS_ACTIVATIONFUNCTION_HPP

#include "Eigen/Dense"

class ActivationFunction {
public:
    virtual Eigen::MatrixXd operator()(const Eigen::MatrixXd& x) const = 0;
    virtual Eigen::MatrixXd derivative(const Eigen::MatrixXd& x) const = 0;
};


class Sigmoid : public ActivationFunction {
public:
    Eigen::MatrixXd operator()(const Eigen::MatrixXd& x) const override {
        return 1 / (1 + (-x).array().exp());
    }

    [[nodiscard]] Eigen::MatrixXd derivative(const Eigen::MatrixXd& x) const override {
        return (*this)(x).array() * (1 - (*this)(x).array());
    }
};

#endif //NNFS_ACTIVATIONFUNCTION_HPP
