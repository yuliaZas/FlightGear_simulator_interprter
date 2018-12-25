//
// Created by Yulia.
//

#include "NotEqual.h"

NotEqual::NotEqual(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double NotEqual::calculate() {
    return this->getLeft()->calculate() != this->getRight()->calculate();
}
