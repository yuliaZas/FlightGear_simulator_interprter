//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_SMALLEREQUAL_H
#define FLIGHT_SIMULATOR_SMALLEREQUAL_H

#include "BinaryExpression.h"

class SmallerEqual : public BinaryExpression{
public:
    double calculate() override;

public:
    SmallerEqual(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_SMALLEREQUAL_H
