//
// Created by Chris Roberts on 5/4/21.
//

#include "Board.h"

void Board::fillVecs(vector<Tile> &tiles, vector<int> &nums) {
    //fill tiles
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

    //fill numbers
    nums.push_back(2);
    for(int i = 3; i <= 11; i++) {
        if(i != 7) {
            nums.push_back(i);
            nums.push_back(i);
        }
    }
    nums.push_back(12);
}

void Board::generate() {
    vector<Tile> tiles;
    vector<int> numbers;
    random_device rand;
    fillVecs(tiles, numbers);
    while(!tiles.empty()) {
        int index = rand() % tiles.size();
        board.push_back(tiles[index]);
        tiles.erase(tiles.begin() + index);
    }
    for(Tile t : board) {
        if(t == Desert) {
            nums.push_back(-1);
        } else {
            int index = rand() % numbers.size();
            nums.push_back(numbers[index]);
            numbers.erase(numbers.begin()+index);
        }
    }
}

void Board::buildGraph() {

}

void Board::print() {
    for(int i = 0; i < board.size(); i++) {
        cout << board[i] << " " << nums[i] << endl;
    }

//    for(Tile t : board) {
//        cout << t << " ";
//    }
//    cout << endl;
//    for(int i : nums) {
//        cout << i << " ";
//    }
//    cout << endl;
}
