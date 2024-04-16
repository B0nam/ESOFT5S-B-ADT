#include "HashTableNode.h"
#include "Product.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
public:
  HashTable(unsigned int initial_length);
  Product *read(std::string name);
  void insert(Product *data);
  void update(Product *data);
  bool remove(std::string name);
  void printAll();
  void rehash();

private:
  HashTableNode **elements;
  unsigned int hashFunction(std::string name);
  unsigned int size;
  unsigned int quantityAdded;
};

#endif