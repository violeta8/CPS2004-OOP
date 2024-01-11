#include "homeappliance.hpp"
#include "product.hpp"

HomeAppliance::HomeAppliance(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model) 
      : Product(id, price, monthPurchase, supplier, packaging, stock), brand_(brand), model_(model){}

void HomeAppliance::setBrand(std::string brand) { brand_ = brand; }

void HomeAppliance::setModel(std::string model) { model_ = model; }

std::string HomeAppliance::getBrand() const { return brand_; }

std::string HomeAppliance::getModel() const { return model_; }

HomeAppliance::~HomeAppliance(){}



//* --------------------------------HomeAppliance concrete subclasses-------------------------------- *//
Fridge::Fridge(int id, double price, int monthPurchase,   Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string energyEfficiency)
        : HomeAppliance(id, price, monthPurchase, supplier, packaging, stock, brand, model), energyEfficiency_(energyEfficiency){}

std::string Fridge::getEnergyEfficiency() const { return energyEfficiency_; }

std::string Fridge::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Model: " + getModel() + "\n";
    info += "Energy efficiency: " + getEnergyEfficiency() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Energy efficiency: " + getEnergyEfficiency() + "\n";
    return info;
}

Fridge::~Fridge(){}


WashingMachine::WashingMachine(int id, double price, int monthPurchas Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string energyEfficiency, bool isAutomatic)
        : HomeAppliance(id, price, monthPurchase, supplier, packaging, stock, brand, model), energyEfficiency_(energyEfficiency), isAutomatic_(isAutomatic){}

void WashingMachine::setEnergyEfficiency(std::string energyEfficiency) { energyEfficiency_ = energyEfficiency; }

void WashingMachine::setIsAutomatic(bool isAutomatic) { isAutomatic_ = isAutomatic; }

std::string WashingMachine::getEnergyEfficiency() const { return energyEfficiency_; }

bool WashingMachine::getIsAutomatic() const { return isAutomatic_; }

std::string WashingMachine::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Model: " + getModel() + "\n";
    info += "Energy efficiency: " + getEnergyEfficiency() + "\n";
    info += "Is automatic: " + std::to_string(getIsAutomatic()) + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Energy efficiency: " + getEnergyEfficiency() + "\n";
    if(getIsAutomatic())
    {
        info += "Automatic: Yes\n";
    }
    else
    {
        info += "Automatic: No\n";
    }
    return info;
}

WashingMachine::~WashingMachine(){}
