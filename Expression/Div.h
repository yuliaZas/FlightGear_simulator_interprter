//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_DIV_H
#define FLIGHT_SIMULATOR_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    double calculate() override;

public:
    Div(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_DIV_H
