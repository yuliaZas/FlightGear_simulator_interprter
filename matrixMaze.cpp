//
// Created by miri on 07/01/19.
//

#include "matrixMaze.h"

matrixMaze::matrixMaze(){
    double cost;
    std::string state;
    for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
        cost = std::rand()/((RAND_MAX + 1u)/6);
        state = std::to_string(i) + "'" + std::to_string(j);
        maze[i][j] = State<std::string> (state, cost);


    }
    }

}
