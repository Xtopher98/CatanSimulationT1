//
// Created by Chris Roberts on 5/4/21.
//

#include "Board.h"

void Board::fillTileVec(vector<Tile> &tiles) {
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
    vector<Tile> tiles;
    random_device rand;
    fillTileVec(tiles);
    while(!tiles.empty()) {
        int index = rand() % tiles.size();
        board.push_back(tiles[index]);
        tiles.erase(tiles.begin() + index);
    }
}

void Board::buildGraph() {

}

void Board::print() {
    for(Tile t : board) {
        cout << t << " ";
    }
    cout << endl;
}
