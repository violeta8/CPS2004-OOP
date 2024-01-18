#include "homeappliance.hpp"

HomeAppliance::HomeAppliance(int id, double price, int volume, Supplier supplier) 
      : Product(id, price, volume, supplier){}

double HomeAppliance::calculate_discount(int quantity, int month)
{
      return Product::calculate_discount(quantity, month);
}

HomeAppliance::~HomeAppliance(){}



//* --------------------------------HomeAppliance concrete subclasses-------------------------------- *//
Fridge::Fridge(int id, double price, int volume, Supplier supplier)
        : HomeAppliance(id, price, volume, supplier){}

std::string Fridge::display_product_info() const
{
      std::string info = "[Fridge: ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Fridge::calculate_discount(int quantity, int month)
{
      return HomeAppliance::calculate_discount(quantity, month);
}

Fridge::~Fridge(){}


WashingMachine::WashingMachine(int id, double price, int volume, Supplier supplier)
        : HomeAppliance(id, price, volume, supplier){}

std::string WashingMachine::display_product_info() const
{
      std::string info = "[WashingMachine, ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double WashingMachine::calculate_discount(int quantity, int month)
{
      return HomeAppliance::calculate_discount(quantity, month);
}

WashingMachine::~WashingMachine(){}
