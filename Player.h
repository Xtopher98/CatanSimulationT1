//
// Created by Chris Roberts on 5/10/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

enum Strategy{beTheBest, looseCannon, duckLips};

class Player {
public:

    Strategy strategy;
    int node1, node2;

    void findNode(const Board& b);

};


#endif //PLAYER_H
