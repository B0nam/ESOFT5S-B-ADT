#include "../include/HashTableNode.h"
#include "../include/HashTable.h"
#include "../include/Product.h"

template <typename class Tkey, class TValue>
HashTable<Tkey, TValue>::HashTable(unsigned int initial_length) {
    elements = new HashTableNode*[initial_length];
    size = initial_length;
}

template <typename class TKey, class TValue>
unsigned int HashTable<TKey, TValue>::hashFunction(TKey key) {
    unsigned int hash = 0;
    for (int i = 0; i < 50; i++) {
        hash += static_cast<unsigned int>(name[i]);
    }
    return hash % size;
}

template <typename class TKey, class TValue>
void  HashTable<TKey, TValue>::insert(TKey, TValue) {
    HashTableNode* node = new HashTableNode(data);

    unsigned int hash = HashTable::hashFunction(product->name);

    if (elements[hash] == nullptr) {
        elements[hash] = node;
    } else {
        HashTableNode* current = elements[hash];
        unsigned int index = hash;
        while (current != nullptr) {
            current = elements[++index];
        }
        elements[index] = node;
    }
}