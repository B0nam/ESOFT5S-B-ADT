#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
  Product(std::string name, unsigned int quantity, double price);
  std::string name;
  double price;
  unsigned int quantity;
};

#endif