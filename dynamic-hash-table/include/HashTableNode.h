#include "Product.h"

#ifndef HASHTABLENODE_H
#define HASHTABLENODE_H

class HashTableNode {
public:
  HashTableNode();
  HashTableNode(Product *product);
  Product *data;
};

#endif