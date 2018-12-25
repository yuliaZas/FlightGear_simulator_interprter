//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_EQUAL_H
#define FLIGHT_SIMULATOR_EQUAL_H

#include "BinaryExpression.h"

class Equal : public BinaryExpression{
public:
    double calculate() override;

public:
    Equal(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_EQUAL_H
