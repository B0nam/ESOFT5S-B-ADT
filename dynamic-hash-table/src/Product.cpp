#include "../include/Product.h"
#include <string>

Product::Product(std::string name, unsigned int quantity, double price) {
  this->name = name;
  this->quantity = quantity;
  this->price = price;
}