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
      std::string info = "Fridge\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
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
      std::string info = "WashingMachine\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double WashingMachine::calculate_discount(int quantity, int month)
{
      return HomeAppliance::calculate_discount(quantity, month);
}

WashingMachine::~WashingMachine(){}
