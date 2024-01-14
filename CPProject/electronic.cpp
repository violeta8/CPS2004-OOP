#include "electronic.hpp"
#include "product.hpp"

Electronic::Electronic(int id, double price, int volume, Supplier supplier, std::string brand) 
      : Product(id, price, volume, supplier), brand_(brand){}

std::string Electronic::getBrand() const { return brand_; }

void Electronic::updateProduct(std::string what, std::string change)
{
      if (what == "brand")
      {
            brand_ = change;
      }
}

Electronic::~Electronic(){}


//* --------------------------------Electronic concrete subclasses-------------------------------- *//
Smartphone::Smartphone(int id, double price, int volume, Supplier supplier, std::string brand, std::string os)
        : Electronic(id, price, volume, supplier, brand), operatingSystem_(os){}

std::string Smartphone::getOperatingSystem() const { return operatingSystem_; }

void Smartphone::updateProduct(std::string what, std::string change)
{
      if (what == "operating system")
      {
            operatingSystem_ = change;
      }
}


std::string Smartphone::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Operating system: " + getOperatingSystem() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

Smartphone::~Smartphone(){}


Tablet::Tablet(int id, double price, int volume, Supplier supplier, std::string brand, std::string model)
        : Electronic(id, price, volume, supplier, brand), model_(model){}

std::string Tablet::getModel() const { return model_; }

void Tablet::updateProduct(std::string what, std::string change)
{
      if (what == "model")
      {
            model_ = change;
      }
}

std::string Tablet::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Model: " + getModel() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

Tablet::~Tablet(){}

