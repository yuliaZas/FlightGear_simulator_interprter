//
// Created by Yulia.
//

#include "Lexer.h"

Lexer::Lexer() {}

vector<string>* Lexer::getVec() {
    return &this->stringVec;
}

void Lexer::read(string str) {
    string temp;
    for (int i = 0; i < str.length() ; ++i) {
        if (str[i] == ' ') {
            if (temp.length() != 0) {
                this->stringVec.push_back(temp);
                temp = "";
            }
            continue;
        }
        else if (str[i] == '\"') {
            temp.push_back(str[i]);
        }
        else {
            temp.push_back(str[i]);
        }
    }
    this->stringVec.push_back(temp);
    return;
}

