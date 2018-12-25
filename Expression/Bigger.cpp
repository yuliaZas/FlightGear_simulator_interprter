//
// Created by Yulia.
//

#include "Bigger.h"

Bigger::Bigger(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Bigger::calculate() {
    return this->getLeft()->calculate() > this->getRight()->calculate();
}
