#include "Player.h"

int main() {

    Board board;

    Player Cannon("Cannon", Ranger);
    Player Chris("Chris", Developer);

    Cannon.node1 = Cannon.findNode(board);
    Chris.node1 = Chris.findNode(board);
    Chris.node2 = Chris.findNode(board);
    Cannon.node2 = Cannon.findNode(board);

    cout << Cannon.name << " places their first settlement on node " << Cannon.node1 << ":\n" << board.nodes[Cannon.node1];
    cout << Chris.name << " places their first settlement on node " << Chris.node1 << ":\n" << board.nodes[Chris.node1];
    cout << Chris.name << " places their second settlement on node " << Chris.node2 << ":\n" << board.nodes[Chris.node2];
    cout << Cannon.name << " places their second settlement on node " << Cannon.node2 << ":\n" << board.nodes[Cannon.node2];



    return 0;
}
