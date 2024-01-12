#include "product.hpp"

//* --------------------------------Product abstract class-------------------------------- *//
Product::Product(int id, double price) 
      : id_(id), price_(price){}

void Product::setId(int id) { id_ = id; }

int Product::getId() const { return id_; }

double Product::getPrice() const { return price_; }

void Product::updateProduct(std::string what, std::string change)
{
      if (what == "price")
      {
            price_ = std::stod(change);
      }
}

double Product::calculate_discount(int quantity, int month) const
{
      if (month == 1 || month == 2 || month == 12) {
            return 0.9 * quantity * price_;
      }
      else if(month == 3 || month == 4 || month == 5) {
            return 0.5 * quantity * price_;
      }
      else if(month == 6 || month == 7 || month == 8) {
            return 0.2 * quantity * price_;
      }
      else if(month == 9 || month == 10 || month == 11) {
            return 0.1 * quantity * price_;
      }
      else {
            return 1;
      }
}

void Product::setPrice(double price) { price_ = price; }

Product::~Product(){}