//
// Created by Chris Roberts on 5/10/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Player.h"

enum Strategy{Collector, Developer, Ranger};

class Player {
public:

                            // Wh    Wo    S     O     B
    vector<double> weightC = {0.25, 0.21, 0.08, 0.25, 0.21};
    vector<double> weightD = {0.36, 0.05, 0.24, 0.40, 0.05};
    vector<double> weightR = {0.17, 0.30, 0.09, 0.13, 0.30};
    //probability of rolling dice and getting the index
    vector<double> weightNums = {0, 0, 1/36, 2/36, 3/36, 4/36, 5/36, 0, 5/36, 4/36, 3/36, 2/36, 1/36};

    Strategy strategy;
//    Node node1;
//    Node node2;

    explicit Player(Strategy s);

    void findNode(const Board& b);

};


#endif //PLAYER_H
