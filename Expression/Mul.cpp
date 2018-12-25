//
// Created by Yulia.
//

#include "Mul.h"

Mul::Mul(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Mul::calculate() {
    return this->getLeft()->calculate() * this->getRight()->calculate();
}
