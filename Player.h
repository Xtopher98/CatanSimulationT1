//
// Created by Chris Roberts on 5/10/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <unordered_set>
#include <queue>

enum Strategy{Collector, Developer, Ranger};

class Player {
private:
                            // Wh    Wo    S     O     B   Be  D
    vector<double> weightC = {0.25, 0.21, 0.08, 0.25, 0.21, 0, 0};
    vector<double> weightD = {0.33, 0.05, 0.22, 0.36, 0.05, 0, 0};
    vector<double> weightR = {0.17, 0.30, 0.09, 0.13, 0.30, 0, 0};
    //probability of rolling 2d6 and getting the index (7 is not used)
    vector<double> weightNums = {0, 0, 0.028, 0.056, 0.083, 0.11, 0.139, 0, 0.139, 0.11, 0.083, 0.056, 0.028};


public:
    string name;
    bool Cplaying = false, Dplaying = false, Rplaying = false;

    Strategy strategy;
    int node1 = -1;
    int node2 = -1;

    Player(string name, Strategy s);

    int findNode(Board& b);

};


#endif //PLAYER_H
