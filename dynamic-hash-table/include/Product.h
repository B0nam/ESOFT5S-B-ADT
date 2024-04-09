#include "NodeData.h"

class Product : public NodeData {
    public:
        Product(char name[50], unsigned int quantity, double price);
        char name[50];
        double price;
        unsigned int quantity;
};