//
// Created by Yulia.
//

#include "Smaller.h"

Smaller::Smaller(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Smaller::calculate() {
    return this->getLeft()->calculate() < this->getRight()->calculate();
}
