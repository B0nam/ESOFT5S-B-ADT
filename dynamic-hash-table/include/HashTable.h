#include "HashTableNode.h"
#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename class TKey, class TValue>
class HashTable {
    public:
        HashTable(unsigned int initial_length);
        void read(TKey key);
        void insert(TKey key, TValue data);
        void update(TKey key,TValue data);
        void remove(TKey key);
    private:
        HashTableNode** elements;
        unsigned int hashFunction(TKey key);
        unsigned int size;
};

#endif