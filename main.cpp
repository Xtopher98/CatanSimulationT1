
#include "Player.h"

int main() {

    Board board;

    Player Cannon(Ranger);
    Player Chris(Developer);
    Cannon.node1 = Cannon.findNode(board);
    Chris.node1 = Chris.findNode(board);
    Chris.node2 = Chris.findNode(board);
    Cannon.node2 = Cannon.findNode(board);

    board.print();

    return 0;
}
