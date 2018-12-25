//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_MUL_H
#define FLIGHT_SIMULATOR_MUL_H

#include "BinaryExpression.h"

class Mul : public BinaryExpression{
public:
    double calculate() override;

public:
    Mul(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_MUL_H
