//
// Created by miri on 07/01/19.
//

#ifndef FLIGHT_SIMULATOR_MATRIXMAZE_H
#define FLIGHT_SIMULATOR_MATRIXMAZE_H


#include "ISearchable.h"
#include "State.h"
#include <string>
const int SIZE = 10;
class matrixMaze:
public ISearchable<std::string> {
private:
    State<std::string> maze[SIZE][SIZE];
public:
     matrixMaze();
     State<std::string> getInitialState();
     State<std::string> getGoalState();
     std::vector<State<std::string>> getAllPossibleStates(State<std::string> s);
};


#endif //FLIGHT_SIMULATOR_MATRIXMAZE_H
