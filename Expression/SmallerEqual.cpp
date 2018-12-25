//
// Created by Yulia.
//

#include "SmallerEqual.h"

SmallerEqual::SmallerEqual(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double SmallerEqual::calculate() {
    return this->getLeft()->calculate() <= this->getRight()->calculate();
}
