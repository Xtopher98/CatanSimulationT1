#include "Simulation.h"

int main() {

    //create players
    vector<Player> players;
    players.emplace_back("Chris", Developer);
    players.emplace_back("Cannon", Ranger);
    players.emplace_back("Ryan",Collector);

    Simulation sim(players, true);

    sim.printBoard();
    cout << endl;
    sim.run();

    return 0;
}
