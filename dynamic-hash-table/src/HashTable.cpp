#include "../include/HashTable.h"
#include "../include/HashTableNode.h"
#include "../include/Product.h"
#include <iostream>
#include <string>

using namespace std;

HashTable::HashTable(unsigned int initial_length) {
  this->elements = new HashTableNode *[initial_length];
  this->size = initial_length;
}

Product *HashTable::read(string name) {
  unsigned int hash = this->hashFunction(name);

  if (this->elements[hash] == nullptr) {
    return nullptr;
  } else {
    Product *productFound = this->elements[hash]->data;
    if (productFound->name.compare(name) == 0) {
      return productFound;
    }
    hash++;
    productFound = this->elements[hash]->data;
    while (productFound->name.compare(name) != 0) {
      hash++;
    }
  }
  return this->elements[hash]->data;
}

bool HashTable::remove(std::string name) {
  unsigned int hash = this->hashFunction(name);
  HashTableNode *element = this->elements[hash];

  if (element == nullptr) {
    return false;
  } else {
    if (element->data->name.compare(name) == 0) {
      this->elements[hash] = nullptr;
      return true;
    }
    hash++;
    Product *productFound = this->elements[hash]->data;
    while (productFound->name.compare(name) != 0) {
      hash++;
    }
    return true;
  }
}

unsigned int HashTable::hashFunction(string name) {
  long hash = 0;
  for (int i = 0; i < name.length(); i++) {
    hash += static_cast<unsigned int>(name[i]);
  }
  return hash % size;
}

void HashTable::insert(Product *product) {
  if (static_cast<double>(this->quantityAdded) /
          static_cast<double>(this->size) >
      0.5) {
    this->rehash();
  }

  HashTableNode *node = new HashTableNode(product);
  unsigned int hash = HashTable::hashFunction(product->name);

  if (elements[hash] == nullptr) {
    elements[hash] = node;
  } else {
    HashTableNode *current = elements[hash];
    unsigned int index = hash;
    while (current != nullptr) {
      current = elements[++index];
    }
    elements[index] = node;
  }
  this->quantityAdded++;
}

void HashTable::rehash() {
  unsigned int oldSize = this->size;
  HashTableNode **oldElements = this->elements;

  this->size *= 2;
  this->elements = new HashTableNode *[this->size];
  this->quantityAdded = 0;

  for (int i = 0; i < oldSize; i++) {
    if (oldElements[i] != nullptr) {
      this->insert(oldElements[i]->data);
    }
  }
  delete[] oldElements;
}

void HashTable::printAll() {
  for (int i = 0; i < this->size; i++) {
    cout << "Index: " << i;
    if (this->elements[i] != nullptr) {
      cout << " -> " << this->elements[i]->data->name;
    } else {
      cout << " -> NULL";
    }
    cout << endl;
  }
}