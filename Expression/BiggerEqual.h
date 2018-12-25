//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_BIGGEREQUAL_H
#define FLIGHT_SIMULATOR_BIGGEREQUAL_H

#include "BinaryExpression.h"

class BiggerEqual : public BinaryExpression{
public:
    double calculate() override;

public:
    BiggerEqual(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_BIGGEREQUAL_H
