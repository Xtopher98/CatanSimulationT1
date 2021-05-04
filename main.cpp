#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum tile {Wheat, Wood, Sheep, Ore, Brick, Desert};
vector<tile> tiles;
vector<tile> board;

void fillTileVec() {
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

void generateBoard() {
    fillTileVec(); //tiles now holds all of the tiles in the game

    while(!tiles.empty()) {
        int index = rand() % tiles.size();
        board.push_back(tiles[index]);
        tiles.erase(tiles.begin() + index);
    }
}

int main() {
    srand(time(nullptr));
    for(int i = 0; i < 10; i++) {
        generateBoard();

        for (tile t : board) {
            cout << t << " ";
        }
        cout <<  endl;
        board.clear();
    }






    return 0;
}
