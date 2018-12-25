//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_NOTEQUAL_H
#define FLIGHT_SIMULATOR_NOTEQUAL_H

#include "BinaryExpression.h"

class NotEqual : public BinaryExpression{
public:
    double calculate() override;

public:
    NotEqual(Expression *left, Expression *rigth);
};


#endif //FLIGHT_SIMULATOR_NOTEQUAL_H
