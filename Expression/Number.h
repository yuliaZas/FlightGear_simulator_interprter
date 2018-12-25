//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_NUMBER_H
#define FLIGHT_SIMULATOR_NUMBER_H

#include "Expression.h"

class Number : public Expression{
private:
    double num;
public:
    Number(double num);
    double calculate() override;
};


#endif //FLIGHT_SIMULATOR_NUMBER_H
