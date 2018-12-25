//
// Created by Yulia.
//

#include "Equal.h"

Equal::Equal(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Equal::calculate() {
    return this->getLeft()->calculate() == this->getRight()->calculate();
}
