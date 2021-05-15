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
    vector<string> tileStrings{"Wheat", "Wood", "Sheep", "Ore", "Brick", "Desert", "Beach"}; //used to print enumeration

    vector<Tile> board;
    vector<int> nums;
    vector<Node> nodes;

    //constructor generates random board
    Board();

    //prints board to console
    void print();

private:
    //fills tiles and numbers with correct distributions
    static void fillVecs(vector<Tile> &tiles, vector<int> &numbers);

    //build a randomized board and distribute numbers
    void generate();

    //take the generated board and build and link all nodes
    void buildGraph();
};

#endif //BOARD_H
