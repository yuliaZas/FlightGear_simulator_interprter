//
// Created by Yulia.
//

#include "ExpressionFactory.h"

ExpressionFactory::ExpressionFactory() {}

Expression* ExpressionFactory::expressionEvaluate(string exp) {
    char prevVal;
    vector<string> *strVec  = stringExpToVec(exp);

    for (string token : *strVec) {
        cout << token << endl;
    }
    /*
    for (int i = 0; i < exp.length() ; i++) {
        if (exp[i] == ' ') {
            continue;
        }
        else if (exp[i] >= '0' || exp[i] <= '9') {
            this->queue1.push(exp[i]);
        }
        else if (exp[i] == '.') {
//            TODO this caes
            if (prevVal >= '0' || prevVal <= '9' ) {}
        }
        else if (isOparator(exp[i])) {
            priorOp(exp[i]);
        }
        else if (exp[i] == '(') {
            this->stack1.push(exp[i]);
        }
        else if (exp[i] == ')') {
            if (this->stack1.top() == '(') {
                this->stack1.pop();
            }
            else {
                this->queue1.push(this->stack1.top());
                this->stack1.pop();
            }
        }
        prevVal = exp[i];
    }
    for (int j = 0; j < this->stack1.size() ; ++j) {
        if (isOparator(this->stack1.top())) {
            this->queue1.push(this->stack1.top());
            this->stack1.pop();
        }
    }
    this->expression = queueToExp();
     */
    this->expression;
}

vector<string>* ExpressionFactory::stringExpToVec(string str) {
    string withoutSpaces;
    vector<string> tokenVec;
    vector<string>* retVec;

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
                    temp += withoutSpaces[0];
                    j = 1;
                    isNeg = true;
                }
            }
            else {
                temp += withoutSpaces[j];
                tokenVec.push_back(temp);
                temp = "";
            }
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
    *retVec = tokenVec;
    return retVec;
}

bool ExpressionFactory::isDig(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    else { return false; }
}

bool ExpressionFactory::isOparator(char op) {
    if (op == '+') { return true; }
    else if (op == '-') { return true; }
    else if (op == '*') { return true; }
    else if (op == '/') { return true; }
    else { return false; }
}

void ExpressionFactory::priorOp(char op) {
    if (op == '+' || op == '-'){
        if (this->stack1.top() == '*') {
            //this->queue1.push(this->stack1.top());
            this->stack1.pop();
            this->stack1.push(op);
        }
        else if (this->stack1.top() == '/') {
            //this->queue1.push(this->stack1.top());
            this->stack1.pop();
            this->stack1.push(op);
        }
        else {
            this->stack1.push(op);
        }
    }
    else if (op == '*' || op == '/') {
        this->stack1.push(op);
    }
    return;
}
/*
Expression* ExpressionFactory::queueToExp() {
    stack<Node> stackNodes;
    if (this->queue1.front()>= '0' || this->queue1.front() <= '9') {
        Expression* number = new Number(this->queue1.front() - '0');
        this->queue1.pop();
        return number;
    }
    switch (this->queue1.back()) {
        case '+':
            this->queue1.pop();

            break;
        case '-':

            break;
        case '*':

            break;
        case '/':

            break;
        default:
            return nullptr;
    }
}
 */