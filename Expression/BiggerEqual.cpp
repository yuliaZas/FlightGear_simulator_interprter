//
// Created by Yulia.
//

#include "BiggerEqual.h"

BiggerEqual::BiggerEqual(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double BiggerEqual::calculate() {
    return this->getLeft()->calculate() >= this->getRight()->calculate();
}
