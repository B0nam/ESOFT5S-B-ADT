#include "NodeData.h"
#ifndef HASHTABLENODE_H
#define HASHTABLENODE_H

class HashTableNode {
    public:
        HashTableNode();
        HashTableNode(NodeData* data);
        NodeData* data;
    private:
        unsigned int key;
};

#endif