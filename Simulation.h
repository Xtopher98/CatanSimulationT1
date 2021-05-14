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

    explicit Simulation(vector<Player> &players);

    void run();

    void printBoard();

};


#endif //SIMULATION_H
