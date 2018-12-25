//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_BIGGER_H
#define FLIGHT_SIMULATOR_BIGGER_H

#include "BinaryExpression.h"

class Bigger : public BinaryExpression{
public:
    double calculate() override;

public:
    Bigger(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_BIGGER_H
