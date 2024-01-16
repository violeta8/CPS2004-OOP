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
      std::string info = "Tablet\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
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
      std::string info = "Smartphone\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double Smartphone::calculate_discount(int quantity, int month)
{
      return Electronic::calculate_discount(quantity, month);
}

Smartphone::~Smartphone(){}

