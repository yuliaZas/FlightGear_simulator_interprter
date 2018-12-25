//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_SMALLER_H
#define FLIGHT_SIMULATOR_SMALLER_H

#include "BinaryExpression.h"

class Smaller : public BinaryExpression {
public:
    double calculate() override;

public:
    Smaller(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_SMALLER_H
