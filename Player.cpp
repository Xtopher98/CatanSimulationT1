//
// Created by Chris Roberts on 5/10/21.
//

#include "Player.h"

#include <utility>

using namespace std;

Player::Player(string n, Strategy s) {
    strategy = s;
    name = std::move(n);
}

int Player::findNode(Board& b) {
    unordered_set<Node*> visited;   //to ensure each node is only visited once
    queue<Node> q;                  //to hold the up next nodes for BFS
    Node maxNodeC = b.nodes[0];      //starting node
    Node maxNodeD=b.nodes[0], maxNodeR=b.nodes[0], maxNode = b.nodes[0];
    q.push(maxNodeC);
    visited.insert(&maxNodeC);

    //node weights
    double maxC = -1,
           maxD = -1,
           maxR = -1;

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

        //check if current node is better than max only if it can be chosen
        if(currentNode.isAvailable) {
            double valueC, valueD, valueR;

            //calculate node value based on strategy

            valueC = weightNums[currentNode.vl] * weightC[currentNode.tl] +
                     weightNums[currentNode.vr] * weightC[currentNode.tr] +
                     weightNums[currentNode.vm] * weightC[currentNode.tm];

            valueD = weightNums[currentNode.vl] * weightD[currentNode.tl] +
                     weightNums[currentNode.vr] * weightD[currentNode.tr] +
                     weightNums[currentNode.vm] * weightD[currentNode.tm];

            valueR = weightNums[currentNode.vl] * weightR[currentNode.tl] +
                     weightNums[currentNode.vr] * weightR[currentNode.tr] +
                     weightNums[currentNode.vm] * weightR[currentNode.tm];


            //update values per strategy
            if (valueC > maxC) {
                maxNodeC = currentNode;
                maxC = valueC;
            }
            if (valueD > maxD) {
                maxNodeD = currentNode;
                maxD = valueD;
            }
            if (valueR > maxR) {
                maxNodeR = currentNode;
                maxR = valueR;
            }
        }
    }

    //decide if it's better to take someone else's strategy's best spot to screw with them or take the best overall
    switch (strategy) {
        case Collector:
            if(0.9 * maxC <= maxD ||0.9 * maxC <= maxR) {
                if(Dplaying && Rplaying)
                    maxNode = maxD > maxR ? maxNodeD : maxNodeR;
                else if(Dplaying)
                    maxNode = maxNodeD;
                else if(Rplaying)
                    maxNode = maxNodeR;
                else
                    maxNode = maxNodeC;
            }
            else
                maxNode = maxNodeC;
            break;
        case Developer:
            if(0.9 * maxD <= maxC ||0.9 * maxD <= maxR) {
                if(Cplaying && Rplaying)
                    maxNode = maxC > maxR ? maxNodeC : maxNodeR;
                else if(Cplaying)
                    maxNode = maxNodeC;
                else if(Rplaying)
                    maxNode = maxNodeR;
                else
                    maxNode = maxNodeD;
            }
            else
                maxNode = maxNodeD;
            break;
        case Ranger:
            if(0.9 * maxR <= maxD ||0.9 * maxR <= maxC) {
                if(Dplaying && Cplaying)
                    maxNode = maxD > maxC ? maxNodeD : maxNodeC;
                else if(Dplaying)
                    maxNode = maxNodeD;
                else if(Cplaying)
                    maxNode = maxNodeC;
                else
                    maxNode = maxNodeR;
            }
            else
                maxNode = maxNodeR;
            break;
    }


    int index = -1;
    for(int i = 0; i < b.nodes.size(); i++) {
        if(maxNode == b.nodes[i]) {
            index = i;
            break;
        }
    }

    //update graph to show that node is taken
    b.nodes[index].isAvailable = false;
    if(b.nodes[index].nl != nullptr)
        b.nodes[index].nl->isAvailable = false;
    if(b.nodes[index].nr != nullptr)
        b.nodes[index].nr->isAvailable = false;
    if(b.nodes[index].nm != nullptr)
        b.nodes[index].nm->isAvailable = false;


    return index;
}

