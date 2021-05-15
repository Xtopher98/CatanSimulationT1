//
// Created by Chris Roberts on 5/13/21.
//

#ifndef SIMULATION_H
#define SIMULATION_H

#include "Player.h"

class Simulation {
public:

    vector<Player> players;
    Board board;

    //randomly generates new board and fills in player information
    Simulation(vector<Player> &players, bool knownStrategies);

    //determines player placing order and causes players to place in the given order
    //prints out information on each placement
    void run();

    //prints the board generated by the simulation to the console
    void printBoard();
};

#endif //SIMULATION_H