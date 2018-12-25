//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_EXPRESSIONFACTORY_H
#define FLIGHT_SIMULATOR_EXPRESSIONFACTORY_H

#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cstring>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Number.h"

using namespace std;

class ExpressionFactory {
private:
    queue<string> queue1;
    stack<char> stack1;
    Expression* expression;

public:
    /**
     * Constructor
     */
    ExpressionFactory();
    /**
     * Evaluate expression into a phrase in a queue which cah be read from right to left.
     * @param exp a string which will be converted into Expression.
     * @return an Expression.
     */
    Expression* expressionEvaluate(string exp);

protected:
    /**
     * Parser a string to tokens
     * @param str the string to parse
     * @return a vector with the tokens
     */
    vector<string>* stringExpToVec(string str);
    /**
     * Checks if the char is a operator
     * @param op the curr char
     * @return true or false
     */
    bool isOparator(char op);
    /**
     * Check if the operator on the top of the stack is with greater precedence
     * @param op the curr operator
     */
    void priorOp(char op);
    /**
     * Read from right to left from a queue and convert it into an expression.
     * @return the converted expression
     */
    Expression* queueToExp();
};


#endif //FLIGHT_SIMULATOR_EXPRESSIONFACTORY_H
