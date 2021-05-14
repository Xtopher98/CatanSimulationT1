//
// Created by Chris Roberts on 5/13/21.
//

#include "Simulation.h"

Simulation::Simulation(vector<Player> &players) {
    this->players = players;
}

void Simulation::run() {
    random_device rand;
    vector<Player> pCpy = players;
    vector<Player> pShuf;

    //shuffle player order
    while(!pCpy.empty()) {
        int index = rand() % pCpy.size();
        pShuf.push_back(pCpy[index]);
        pCpy.erase(pCpy.begin()+index);
    }

    //run simulation
    for(Player &p : pShuf) {
        p.node1 = p.findNode(board);
        cout << p.name << " places their first settlement on node " << p.node1 << ":\n" << board.nodes[p.node1];
    }
    for(int i = pShuf.size() - 1; i >= 0; i--) {
        pShuf[i].node2 = pShuf[i].findNode(board);
        cout << pShuf[i].name << " places their second settlement on node " << pShuf[i].node2 << ":\n" << board.nodes[pShuf[i].node2];
    }
    players = pShuf;

}

void Simulation::printBoard() {
    board.print();
}
