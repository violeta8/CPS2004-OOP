#include "food.hpp"

Food::Food(int id, double price, int volume, Supplier supplier) 
      : Product(id, price, volume, supplier){}

double Food::calculate_discount(int quantity, int month)
{
      return Product::calculate_discount(quantity, month);
}

Food::~Food(){}



//* --------------------------------Food concrete subclasses-------------------------------- *//
Milk::Milk(int id, double price, int volume, Supplier supplier)
        : Food(id, price, volume, supplier){}

std::string Milk::display_product_info() const
{
      std::string info = "[Milk: ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Milk::calculate_discount(int quantity, int month)
{
      return Food::calculate_discount(quantity, month);
}

Milk::~Milk(){}


Cheese::Cheese(int id, double price, int volume, Supplier supplier)
        : Food(id, price, volume, supplier){}

std::string Cheese::display_product_info() const
{
      std::string info = "Cheese: ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Cheese::calculate_discount(int quantity, int month)
{
      return Food::calculate_discount(quantity, month);
}

Cheese::~Cheese(){}
