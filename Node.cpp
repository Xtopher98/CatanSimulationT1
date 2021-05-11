//
// Created by Chris Roberts on 5/5/21.
//

#include "Node.h"

Node::Node(Tile tl, Tile tr, Tile tm, int vl, int vr, int vm) {
    this->tl = tl;
    this->tr = tr;
    this->tm = tm;
    this->vl = vl;
    this->vr = vr;
    this->vm = vm;
}

bool Node::operator==(Node n) const {
    if( this->tl != n.tl ||
        this->tr != n.tr ||
        this->tm != n.tm ||
        this->vl != n.vl ||
        this->vr != n.vr ||
        this->vm != n.vm
        ) {
        return false;
    }
    else return true;
}
