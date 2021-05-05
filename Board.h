//
// Created by Chris Roberts on 5/4/21.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <random>
#include "Node.h"

using namespace std;


class Board {
public:

    vector<Tile> board;

    Board() = default;

    static void fillTileVec(vector<Tile> &tiles);
    void generate();
    void buildGraph();
    void print();

};


#endif //BOARD_H
