//
// Created by Yulia.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *rigth) {
    this->left = left;
    this->right = rigth;
}

Expression* BinaryExpression::getLeft() {
    return this->left;
}

Expression* BinaryExpression::getRight() {
    return this->right;
}