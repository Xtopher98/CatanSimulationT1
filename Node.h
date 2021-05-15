//
// Created by Chris Roberts on 5/5/21.
//

#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <vector>

enum Tile {Wheat, Wood, Sheep, Ore, Brick, Desert, Beach};

class Node {
public:
    std::vector<std::string> tileStrings{"Wheat", "Wood", "Sheep", "Ore", "Brick", "Desert", "Beach"}; //used in printing enumeration
    Tile tl, tr, tm; //adjacent tiles
    int vl, vr, vm; //values of tiles
    Node* nl = nullptr, *nr = nullptr, *nm = nullptr; //adjacent nodes
    bool isAvailable = true; //can a settlement be placed at this node

    //constructor
    Node(Tile tl, Tile tr, Tile tm, int vl, int vr, int vm);

    //overloaded equals operator for comparison
    bool operator==(const Node& n) const;

    //overloaded stream operator for easy printing to console
    friend std::ostream& operator<<(std::ostream& os, const Node& n);
};

#endif //NODE_H
