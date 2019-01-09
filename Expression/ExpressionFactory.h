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
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Number.h"
#include "Bigger.h"
#include "BiggerEqual.h"
#include "Smaller.h"
#include "SmallerEqual.h"
#include "Equal.h"

#define LEN_OP 1

using namespace std;

class ExpressionFactory {
private:
    queue<string> queue1;
    stack<string> stackOp;
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
    vector<string> stringExpToVec(string str);
    /**
     * Checks if the char is a digit
     * @param ch the curr char
     * @return true or false
     */
    bool isDig(char ch);
    /**
     * Checks if the char is a operator
     * @param the curr char
     * @return true or false
     */
    bool isOparator(char op);
    /**
     * Checks if the string is a operator
     * @param the curr string
     * @return true or false
     */
    bool isOparatorStr(string str);
    /**
     * Check if the operator on the top of the stack is with greater precedence
     * @param curr the curr operator
     * @param top the top of the operator stack
     * @return true or false
     */
    bool priorOp(string curr, string top);
    /**
     * Check is a string is number
     * @param str the string to check
     * @return true or false
     */
    bool isNum(string str);
    /**
     * Read from right to left from a queue and convert it into an expression.
     * @param str the postfix expression
     * @return the converted expression
     */
    Expression* getExp(vector<string> str);
    /**
     * The function takes an infix numeric expression and converts it to a postfix one
     * @param str the infix expression
     * @return the postfix version of the expression
     */
    vector<string> stringToPostfix(vector<string> str);
};


#endif //FLIGHT_SIMULATOR_EXPRESSIONFACTORY_H
