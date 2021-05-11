//
// Created by Chris Roberts on 5/5/21.
//

#ifndef NODE_H
#define NODE_H

enum Tile {Wheat, Wood, Sheep, Ore, Brick, Desert, Beach};

class Node {
public:
    Tile tl, tr, tm; //adjacent tiles
    int vl, vr, vm; //values of tiles
    Node* nl = nullptr, *nr = nullptr, *nm = nullptr; //adjacent nodes
    bool isAvailable = true; //can a settlement be placed at this node

    Node(Tile tl, Tile tr, Tile tm, int vl, int vr, int vm);

    bool operator==(Node n) const;

};


#endif //NODE_H
