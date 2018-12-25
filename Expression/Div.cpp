//
// Created by Yulia.
//

#include "Div.h"

Div::Div(Expression *left, Expression *rigth) : BinaryExpression(left, rigth) {}

double Div::calculate() {
    return this->getLeft()->calculate() / this->getRight()->calculate();
}
