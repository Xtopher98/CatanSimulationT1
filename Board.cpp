//
// Created by Chris Roberts on 5/4/21.
//

#include "Board.h"

Board::Board() {
    generate();
    buildGraph();
}

void Board::fillVecs(vector<Tile> &tiles, vector<int> &numbers) {
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
    numbers.push_back(2);
    for(int i = 3; i <= 11; i++) {
        if(i != 7) {
            numbers.push_back(i);
            numbers.push_back(i);
        }
    }
    numbers.push_back(12);
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
            nums.push_back(0);
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
        nodes.emplace_back(Beach, Beach, board[i], 0, 0, nums[i]);
    //3-6
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i>0?board[i-1]:Beach, i<3?board[i]:Beach, Beach, i>0?nums[i-1]:0, i<3?nums[i]:0, 0);
    //7-10
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i>0?board[i-1]:Beach, i<3?board[i]:Beach, board[i+3], i>0?nums[i-1]:0, i<3?nums[i]:0, nums[i+3]);
    //11-15
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i>0?board[i+2]:Beach, i<4?board[i+3]:Beach, (i>0 && i<4)?board[i-1]:Beach, i>0?nums[i+2]:0, i<4?nums[i+3]:0, (i>0 && i<4)?nums[i-1]:0);
    //16-20
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i>0?board[i+2]:Beach, i<4?board[i+3]:Beach, board[i+7], i>0?nums[i+2]:0, i<4?nums[i+3]:0, nums[i+7]);
    //21-26
    for(int i = 0; i < 6; i++)
        nodes.emplace_back(i>0?board[i+6]:Beach, i<5?board[i+7]:Beach, (i>0 && i<5)?board[i+2]:Beach, i>0?nums[i+6]:0, i<5?nums[i+7]:0, (i>0 && i<5)?nums[i+2]:0);
    //27-32
    for(int i = 0; i < 6; i++)
        nodes.emplace_back(i>0?board[i+6]:Beach, i<5?board[i+7]:Beach, (i>0 && i<5)?board[i+11]:Beach, i>0?nums[i+6]:0, i<5?nums[i+7]:0, (i>0 && i<5)?nums[i+11]:0);
    //33-37
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i>0?board[i+11]:Beach, i<4?board[i+12]:Beach, board[i+7], i>0?nums[i+11]:0, i<4?nums[i+12]:0, nums[i+7]);
    //38-42
    for(int i = 0; i < 5; i++)
        nodes.emplace_back(i>0?board[i+11]:Beach, i<4?board[i+12]:Beach, (i>0 && i<4)?board[i+15]:Beach, i>0?nums[i+11]:0, i<4?nums[i+12]:0, (i>0 && i<4)?nums[i+15]:0);
    //43-46
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i>0?board[i+15]:Beach, i<3?board[i+16]:Beach, board[i+12], i>0?nums[i+15]:0, i<3?nums[i+16]:0, nums[i+12]);
    //47-50
    for(int i = 0; i < 4; i++)
        nodes.emplace_back(i>0?board[i+15]:Beach, i<3?board[i+16]:Beach, Beach, i>0?nums[i+15]:0, i<3?nums[i+16]:0,0);
    //51-53
    for(int i = 0; i < 3; i++)
        nodes.emplace_back(Beach, Beach, board[i+16], 0, 0, nums[i+16]);

    //connect nodes

    //0-2,51-53
    for(int i = 0; i < 3; i++) {
        nodes[i].nl = &nodes[i+3];
        nodes[i].nr = &nodes[i+4];

        nodes[i+51].nl = &nodes[i+47];
        nodes[i+51].nr = &nodes[i+48];
    }

    //3-6,47-50,7-10,43-46
    for(int i = 0; i < 4; i++) {
        nodes[i+3].nm = &nodes[i+7];
        nodes[i+3].nl = i > 0 ? &nodes[i-1] : nullptr;
        nodes[i+3].nr = i < 3 ? &nodes[i] : nullptr;

        nodes[i+47].nm = &nodes[i+43];
        nodes[i+47].nl = i > 0 ? &nodes[i+50] : nullptr;
        nodes[i+47].nr = i < 3 ? &nodes[i+51] : nullptr;

        nodes[i+7].nm = &nodes[i+3];
        nodes[i+7].nl = &nodes[i+11];
        nodes[i+7].nr = &nodes[i+12];

        nodes[i+43].nm = &nodes[i+47];
        nodes[i+43].nl = &nodes[i+38];
        nodes[i+43].nr = &nodes[i+39];
    }

    //11-15,38-42,16-20,33-37
    for(int i = 0; i < 5; i++) {
        nodes[i+11].nm = &nodes[i+16];
        nodes[i+11].nl = i > 0 ? &nodes[i+6] : nullptr;
        nodes[i+11].nr = i < 4 ? &nodes[i+7] : nullptr;

        nodes[i+38].nm = &nodes[i+33];
        nodes[i+38].nl = i > 0 ? &nodes[i+42] : nullptr;
        nodes[i+38].nr = i < 4 ? &nodes[i+43] : nullptr;

        nodes[i+16].nm = &nodes[i+11];
        nodes[i+16].nl = &nodes[i+21];
        nodes[i+16].nr = &nodes[i+22];

        nodes[i+33].nm = &nodes[i+38];
        nodes[i+33].nl = &nodes[i+27];
        nodes[i+33].nr = &nodes[i+28];
    }

    //21-26,27-32
    for(int i = 0; i < 6; i++){
        nodes[i+21].nm = &nodes[i+27];
        nodes[i+21].nl = i > 0 ? &nodes[i+15] : nullptr;
        nodes[i+21].nr = i < 5 ? &nodes[i+16] : nullptr;

        nodes[i+27].nm = &nodes[i+21];
        nodes[i+27].nl = i > 0 ? &nodes[i+32] : nullptr;
        nodes[i+27].nr = i < 5 ? &nodes[i+33] : nullptr;
    }
}

void Board::print() {
    for(int i = 0; i < board.size(); i++) {
        cout << tileStrings[board[i]] << "->" << nums[i] << endl;
    }
}


