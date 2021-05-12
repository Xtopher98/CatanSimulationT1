//
// Created by Chris Roberts on 5/4/21.
//

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <random>
#include "Node.h"

using namespace std;


class Board {
public:

    vector<Tile> board;
    vector<int> nums;
    vector<Node> nodes;

    //constructor generates random board
    Board();

    void print();

private:
    static void fillVecs(vector<Tile> &tiles, vector<int> &numbers);
    void generate();
    void buildGraph();

};


#endif //BOARD_H
