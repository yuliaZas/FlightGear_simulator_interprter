//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_BINARYEXPRESSION_H
#define FLIGHT_SIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
private:
    Expression* left;
    Expression* right;
protected:
    virtual Expression* getLeft();
    virtual Expression* getRight();
public:
    BinaryExpression(Expression* left, Expression* rigth);
    virtual double calculate() override = 0;
};


#endif //FLIGHT_SIMULATOR_BINARYEXPRESSION_H
