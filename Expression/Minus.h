//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_MINUS_H
#define FLIGHT_SIMULATOR_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
public:
    double calculate() override;

public:
    Minus(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_MINUS_H
