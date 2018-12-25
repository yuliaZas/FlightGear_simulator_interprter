//
// Created by Yulia.
//

#ifndef FLIGHT_SIMULATOR_LEXER_H
#define FLIGHT_SIMULATOR_LEXER_H

#include <vector>
#include <string>

using namespace std;

class Lexer {
private:
    vector<string> stringVec;
public:
    /**
     * Constructor.
     */
    Lexer();
    /**
     * Read a line and store every significent string in it in the vector.
     * @param str the line to read from
     */
    void read(string str);
    /**
     * Getter
     * @return the vector with the strings.
     */
    vector<string>* getVec();
};


#endif //FLIGHT_SIMULATOR_LEXER_H
