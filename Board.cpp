//
// Created by Chris Roberts on 5/4/21.
//

#include "Board.h"

void Board::fillTileVec(vector<tile> &tiles) {
    for(int i = 0; i < 4; i++) {
        tiles.push_back(Wheat);
        tiles.push_back(Wood);
        tiles.push_back(Sheep);
        if(i < 3) {
            tiles.push_back(Ore);
            tiles.push_back(Brick);
        }
    }
    tiles.push_back(Desert);
}

void Board::generate() {
    vector<tile> tiles;
    random_device rand;
    fillTileVec(tiles);
    while(!tiles.empty()) {
        int index = rand() % tiles.size();
        board.push_back(tiles[index]);
        tiles.erase(tiles.begin() + index);
    }
}

void Board::print() {
    for(tile t : board) {
        cout << t << " ";
    }
    cout << endl;
}
