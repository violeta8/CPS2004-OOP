#include "clothing.hpp"

Clothing::Clothing(int id, double price, int volume, Supplier supplier)
      : Product(id, price, volume, supplier){}

double Clothing::calculate_discount(int quantity, int month)
{
      return Product::calculate_discount(quantity, month);
}

Clothing::~Clothing(){}


//* --------------------------------Clothing concrete subclasses-------------------------------- *//
TShirt::TShirt(int id, double price, int volume, Supplier supplier)
        : Clothing(id, price, volume, supplier){}

std::string TShirt::display_product_info() const
{
      std::string info = "[T-Shirt: ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double TShirt::calculate_discount(int quantity, int month)
{
      return Clothing::calculate_discount(quantity, month);
}

TShirt::~TShirt(){}


Pants::Pants(int id, double price, int volume, Supplier supplier)
        : Clothing(id, price, volume, supplier){}

std::string Pants::display_product_info() const
{
      std::string info = "[Pants: ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Pants::calculate_discount(int quantity, int month)
{
      return Clothing::calculate_discount(quantity, month);
}

Pants::~Pants(){}

