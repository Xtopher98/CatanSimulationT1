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

    //build all nodes

    //0-2
    for(int i = 0; i < 3; i++)
        nodes.emplace_back(Beach, Beach, board[i]);
    //3-6
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i-1>=0?board[i-1]:Beach, i<=2?board[i]:Beach,Beach);
    //7-10
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i-1>=0?board[i-1]:Beach, i<=2?board[i]:Beach, board[i+3]);
    //11-15
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i+2>=3?board[i+2]:Beach, i+3<=6?board[i+3]:Beach, (i-1>=0 || i<=3)?board[i]:Beach);
    //16-20
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i+2>=3?board[i+2]:Beach, i+3<=6?board[i+3]:Beach, board[i+7]);
    //21-26
    for(int i = 0; i < 6; i++)
        nodes.emplace_back(i+6>=7?board[i+6]:Beach, i+7<=11?board[i+7]:Beach, (i-1>=0|| i<=4)?board[i+3]:Beach);
    //27-32
    for(int i = 0; i < 6; i++)
        nodes.emplace_back(i+6>=7?board[i+6]:Beach, i+7<=11?board[i+7]:Beach, (i-1>=0|| i<=4)?board[i+12]:Beach);
    //33-37
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i+2>=3?board[i+11]:Beach, i+3<=6?board[i+12]:Beach, board[i+7]);
    //38-42
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i+2>=3?board[i+11]:Beach, i+3<=6?board[i+12]:Beach, (i-1>=0 || i<=3)?board[i+16]:Beach);
    //43-46
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i-1>=0?board[i+15]:Beach, i<=2?board[i+16]:Beach, board[i+12]);
    //47-50
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i-1>=0?board[i+15]:Beach, i<=2?board[i+16]:Beach,Beach);
    //51-53
    for(int i = 0; i < 3; i++)
        nodes.emplace_back(Beach, Beach, board[i+16]);

    //connect nodes
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
