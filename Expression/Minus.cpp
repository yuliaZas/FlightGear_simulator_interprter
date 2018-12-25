//
// Created by Yulia.
//

#include "Minus.h"

Minus::Minus(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Minus::calculate() {
    return this->getLeft()->calculate() - this->getRight()->calculate();
}
