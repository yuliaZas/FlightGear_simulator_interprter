//
// Created by Yulia.
//

#include "ExpressionFactory.h"

ExpressionFactory::ExpressionFactory() {}

Expression* ExpressionFactory::expressionEvaluate(string exp) {
    char prevVal;
    vector<string> exp = stringExpToVec(exp);

    for (string token : exp) {
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
    vector<string> tokenVec;
    string temp = "";
    for (int i = 0; i < str.length() ; ++i) {
        if (str[i] == ' '){
            if (temp == "") {continue;}
            else {
                tokenVec.push_back(temp);
            }
        }
        else if (isOparator(str[i])) {
            if (temp == "") {
                temp = str[i];
                tokenVec.push_back(temp);
            }
            else {
                //push the token before the operator
                tokenVec.push_back(temp);
                //push the operator
                temp = str[i];
                tokenVec.push_back(temp);
            }
        }
        else {
            temp.push_back(str[i]);
        }
        temp = "";
    }
    return &tokenVec;
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