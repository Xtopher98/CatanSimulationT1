
#include "Board.h"

int main() {

    Board board;
    board.generate();
    board.buildGraph();
    board.print();


    return 0;
}
