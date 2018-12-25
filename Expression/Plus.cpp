//
// Created by Yulia.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Plus::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
};
