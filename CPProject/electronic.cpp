#include "electronic.hpp"

Electronic::Electronic(int id, double price, int volume, Supplier supplier) 
      : Product(id, price, volume, supplier){}

double Electronic::calculate_discount(int quantity, int month)
{
      return Product::calculate_discount(quantity, month);
}

Electronic::~Electronic(){}



//* --------------------------------Electronic concrete subclasses-------------------------------- *//
Tablet::Tablet(int id, double price, int volume, Supplier supplier)
        : Electronic(id, price, volume, supplier){}

std::string Tablet::display_product_info() const
{
      std::string info = "[Tablet, ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Tablet::calculate_discount(int quantity, int month)
{
      return Electronic::calculate_discount(quantity, month);
}

Tablet::~Tablet(){}


Smartphone::Smartphone(int id, double price, int volume, Supplier supplier)
        : Electronic(id, price, volume, supplier){}

std::string Smartphone::display_product_info() const
{
      std::string info = "Smartphone, ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Smartphone::calculate_discount(int quantity, int month)
{
      return Electronic::calculate_discount(quantity, month);
}

Smartphone::~Smartphone(){}

