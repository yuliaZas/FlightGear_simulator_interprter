//
// Created by Yulia.
//

#include "ExpressionFactory.h"

ExpressionFactory::ExpressionFactory() {}

Expression* ExpressionFactory::expressionEvaluate(string exp) {

    vector<string> strVec  = stringExpToVec(exp);

    vector<string> strPostfix = stringToPostfix(strVec);

    this->expression = getExp(strPostfix);

    return this->expression;
}

vector<string> ExpressionFactory::stringExpToVec(string str) {
    string withoutSpaces;
    vector<string> tokenVec;

    //making a string with out spaces
    for (int i = 0; i < str.length() ; ++i) {
        if (str[i] == ' '){
            continue;
        }
        else {
            withoutSpaces.push_back(str[i]);
        }
    }
    string temp = "";
    int j = 0;
    bool isNeg = false;
    //if the first number is negative
    if (str[0] == '-') {
        temp += withoutSpaces[0];
        j = 1;
        isNeg = true;
    }
    //parsing the string to tokens and store it in a vector
    for (; j < withoutSpaces.length() ; j++) {
        if (isNeg) {
            while (isDig(withoutSpaces[j]) || withoutSpaces[j] == '.') {
                temp += withoutSpaces[j];
                j++;
            }
            isNeg = false;
            j--;
            tokenVec.push_back(temp);
            temp = "";
        }
        else if (isOparator(withoutSpaces[j])){
            //negative num
            if (withoutSpaces[j] == '-') {
                if (isOparator(withoutSpaces[j-1])) {
                    temp += withoutSpaces[j];
                    isNeg = true;
                }
            }
            else {
                temp += withoutSpaces[j];
                tokenVec.push_back(temp);
                temp = "";
            }
        }
        else if (withoutSpaces[j] == '(' || withoutSpaces[j] == ')') {
            temp += withoutSpaces[j];
            tokenVec.push_back(temp);
            temp = "";
        }
        else {
            while (isDig(withoutSpaces[j]) || withoutSpaces[j] == '.') {
                temp += withoutSpaces[j];
                j++;
            }
            tokenVec.push_back(temp);
            j--;
            temp = "";
        }
    }
    return tokenVec;
}

vector<string> ExpressionFactory::stringToPostfix(vector<string> strVec) {
    vector<string> resultArray;
    for (string token : strVec) {
        if (isNum(token)) {
            this->queue1.push(token);
        }
        else if (isOparatorStr(token)) {
            string curOperator = token;

            /* While there is an operator with greater precedence in the stack, pop it to the queue */
            if (!this->stackOp.empty()) {
                string top = this->stackOp.top();
                while (!this->stackOp.empty() && priorOp(top, curOperator)) {
                    this->stackOp.pop(); //pop the operator from the stack
                    this->queue1.push(top); //add the operator to the queue
                    //top = this->stackOp.top();
                }
            }
            //push the current operator onto the stack
            this->stackOp.push(curOperator);
        }
        else if (token == "(") {
            this->stackOp.push(token);
        }
        else if (token == ")") {
            /* While there's not a left bracket at the top of the stack
              Pop operators from the stack onto the output queue.*/
            while (!this->stackOp.empty() && (this->stackOp.top() != "(")) {
                string top = this->stackOp.top();
                this->queue1.push(top);
                this->stackOp.pop();

            }
            //pop the left bracket from the stack and discard it
            this->stackOp.pop();
        }
    }
    //while there are operators on the stack, pop them to the queue
    while (!this->stackOp.empty()) {
        string top = this->stackOp.top();
        if (top != "(" && top != ")") {
            this->queue1.push(top);
            this->stackOp.pop();
        }
    }

    //move the queue to the array
    while (!this->queue1.empty()) {
        resultArray.push_back(this->queue1.front());
        this->queue1.pop();
    }
    return resultArray;
}

Expression* ExpressionFactory::getExp(vector<string> str) {
    stack<Expression*> expressionStack;
    for (string token : str) {
        //If the current string is an operator
        if (isOparatorStr(token)) {
            char oper = token[0];
            //take two numbers out of the stack
            Expression* num2 = expressionStack.top();
            expressionStack.pop();
            Expression* num1 = expressionStack.top();
            expressionStack.pop();

            //create the expression with the two numbers
            Expression* exp;
            switch (oper) {
                case '+':
                    exp = new Plus(num1, num2);
                    break;
                case '-':
                    exp = new Minus(num1, num2);
                    break;
                case '*':
                    exp = new Mul(num1, num2);
                    break;
                case '/':
                    exp = new Div(num1, num2);
                    break;
                case '>':
                    if (token.length() > LEN_OP) { // ">="
                        exp = new BiggerEqual(num1, num2);
                    }
                    else {
                        exp = new Bigger(num1, num2);
                    }
                    break;
                case '<':
                    if (token.length() > LEN_OP) { // "<="
                        exp = new SmallerEqual(num1, num2);
                    }
                    else {
                        exp = new Smaller(num1, num2);
                    }
                    break;
                case '=': //"=="
                    exp = new Equal(num1, num2);
                    break;
                default:
                    throw "Operator is unknown";
            }
            //Push the created expression to the stack;
            expressionStack.push(exp);
        } else { //The current string is a number
            //convert the string to double and push it the stack
            expressionStack.push(new Number(stod(token)));
        }
    }
    //There should be one item in the stack which is the return value.
    if (expressionStack.size() != 1) {
        throw "Something went wrong with the algorithm.";
    }
    return expressionStack.top();
}

bool ExpressionFactory::isDig(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    else { return false; }
}

bool ExpressionFactory::isOparator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '=' || op == '==' ||
            op == '<' || op == '<=' || op == '>' || op == '>=') {
        return true;
    } else {
        return false;
    }
}

bool ExpressionFactory::isOparatorStr(string str) {
    if (str == "+" || str == "-" || str == "*" || str == "/" || str == "=" ||
            str == "==" || str == "<" || str == "<=" || str == ">" || str == ">=") {
        return true;
    } else {
        return false;
    }
}

bool ExpressionFactory::priorOp(string curr, string top) {
    if (curr == "*" || curr == "/") {
        if (top == "+" || top == "-") {
            return true;
        }
    }
    if ((curr == ">" || curr == "<" || curr == "==" || curr == "<=" || curr == ">=")) {
        if (top == "*" || top == "/" || top == "+" || top == "-") {
            return true;
        }
    }
    else {
        return false;
    }
}

bool ExpressionFactory::isNum(string str) {
    bool ret = true;
    for (int i = 0; i < str.length(); ++i) {
        if (!isDig(str[i])) {
            ret = false;
        }
    }
    return ret;
}
