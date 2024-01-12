#include "homeappliance.hpp"
#include "product.hpp"

HomeAppliance::HomeAppliance(int id, double price, std::string brand) 
      : Product(id, price), brand_(brand){}

std::string HomeAppliance::getBrand() const { return brand_; }

void HomeAppliance::updateProduct(std::string what, std::string change)
{
      if (what == "brand")
      {
            brand_ = change;
      }
}

HomeAppliance::~HomeAppliance(){}



//* --------------------------------HomeAppliance concrete subclasses-------------------------------- *//
Fridge::Fridge(int id, double price, std::string brand, std::string model)
        : HomeAppliance(id, price, brand), model_(model){}

std::string Fridge::getModel() const { return model_; }

void Fridge::updateProduct(std::string what, std::string change)
{
      if (what == "model")
      {
            model_ = change;
      }
}

std::string Fridge::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Model: " + getModel() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

Fridge::~Fridge(){}


WashingMachine::WashingMachine(int id, double price, std::string brand, std::string energyEfficiency)
        : HomeAppliance(id, price, brand), energyEfficiency_(energyEfficiency){}

std::string WashingMachine::getEnergyEfficiency() const { return energyEfficiency_; }

void WashingMachine::updateProduct(std::string what, std::string change)
{
      if (what == "energy efficiency")
      {
            energyEfficiency_ = change;
      }
}

std::string WashingMachine::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Energy efficiency: " + getEnergyEfficiency() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

WashingMachine::~WashingMachine(){}
