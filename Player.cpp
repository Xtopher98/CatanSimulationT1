//
// Created by Chris Roberts on 5/10/21.
//

#include "Player.h"
#include <unordered_set>
#include <queue>

using namespace std;

void Player::findNode(const Board& b) {
    //starting with general BFS and will make more specific per strategy later

    unordered_set<Node*> visited;
    queue<Node> q;
    q.push(b.nodes[0]);

    //run until every node is visited
    while(!q.empty()) {
        Node currentNode = q.front(); q.pop(); //get next node from queue

        //add adjacent Nodes to queue if they haven't been visited yet
        if(currentNode.nl != nullptr && !visited.count(currentNode.nl))
            q.push(*currentNode.nl);
        if(currentNode.nr != nullptr && !visited.count(currentNode.nr))
            q.push(*currentNode.nr);
        if(currentNode.nm != nullptr && !visited.count(currentNode.nm))
            q.push(*currentNode.nm);

        //add current node to set to make sure we don't visit it again
        visited.insert(&currentNode);
    }



}
