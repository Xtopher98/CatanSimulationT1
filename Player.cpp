//
// Created by Chris Roberts on 5/10/21.
//

#include "Player.h"
#include <unordered_set>
#include <queue>

using namespace std;

Player::Player(Strategy s) {
    strategy = s;
}


void Player::findNode(const Board& b) {
    unordered_set<Node*> visited;   //to ensure each node is only visited once
    queue<Node> q;                  //to hold the up next nodes for BFS
    Node maxNode = b.nodes[0];    //starting node
    q.push(maxNode);
    visited.insert(&maxNode);

    double max = -1; //node weight

    //run until every node is visited
    while(!q.empty()) {
        Node currentNode = q.front(); q.pop(); //get next node from queue

        //add adjacent Nodes to queue if they haven't been visited yet
        if(currentNode.nl != nullptr && !visited.count(currentNode.nl)) {
            q.push(*currentNode.nl);
            visited.insert(currentNode.nl);
        }
        if(currentNode.nr != nullptr && !visited.count(currentNode.nr)) {
            q.push(*currentNode.nr);
            visited.insert(currentNode.nr);
        }
        if(currentNode.nm != nullptr && !visited.count(currentNode.nm)) {
            q.push(*currentNode.nm);
            visited.insert(currentNode.nm);
        }

        //check if current node is better than max
        double value;

        switch (strategy) {
            case Collector:
                value = weightNums[currentNode.vl]*weightC[currentNode.tl] + weightNums[currentNode.vr]*weightC[currentNode.tr] + weightNums[currentNode.vm]*weightC[currentNode.tm];
                break;
            case Developer:
                value = weightNums[currentNode.vl]*weightD[currentNode.tl] + weightNums[currentNode.vr]*weightD[currentNode.tr] + weightNums[currentNode.vm]*weightD[currentNode.tm];
                break;
            case Ranger:
                value = weightNums[currentNode.vl]*weightR[currentNode.tl] + weightNums[currentNode.vr]*weightR[currentNode.tr] + weightNums[currentNode.vm]*weightR[currentNode.tm];
                break;
        }
        if(value > max) {
            maxNode = currentNode;
            max = value;
        }
    }

    //update graph to show that node is taken

//    if(node1 != nullptr) {
//        node2 = &maxNode;
//    }

    //add found node to node1 or node2

}

