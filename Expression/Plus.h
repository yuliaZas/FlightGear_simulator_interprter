//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_PLUS_H
#define FLIGHT_SIMULATOR_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression *left, Expression *rigth);

    double calculate() override;
};


#endif //FLIGHT_SIMULATOR_PLUS_H
