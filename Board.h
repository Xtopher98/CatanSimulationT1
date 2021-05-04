//
// Created by Chris Roberts on 5/4/21.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <random>

using namespace std;


class Board {
public:
    enum tile {Wheat, Wood, Sheep, Ore, Brick, Desert};
    vector<tile> board;

    Board() = default;

    static void fillTileVec(vector<tile> &tiles);
    void generate();
    void print();

};


#endif BOARD_H
