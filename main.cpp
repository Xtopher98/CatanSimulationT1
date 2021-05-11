
#include "Player.h"

int main() {

    Board board;

    Player Cannon(Developer);
    Cannon.findNode(board);
    board.print();

    return 0;
}
