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
      std::string info = "Milk\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
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
      std::string info = "Cheese\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double Cheese::calculate_discount(int quantity, int month)
{
      return Food::calculate_discount(quantity, month);
}

Cheese::~Cheese(){}
