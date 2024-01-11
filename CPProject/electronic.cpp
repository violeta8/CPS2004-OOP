#include "electronic.hpp"
#include "product.hpp"

Electronic::Electronic(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model) 
      : Product(id, price, monthPurchase, supplier, packaging, stock), brand_(brand), model_(model){}

void Electronic::setBrand(std::string brand) { brand_ = brand; }

void Electronic::setModel(std::string model) { model_ = model; }

std::string Electronic::getBrand() const { return brand_; }

std::string Electronic::getModel() const { return model_; }

Electronic::~Electronic(){}


//* --------------------------------Electronic concrete subclasses-------------------------------- *//
Smartphone::Smartphone(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string os)
        : Electronic(id, price, monthPurchase, supplier, packaging, stock, brand, model), operatingSystem_(os){}

void Smartphone::setOperatingSystem(std::string os) { operatingSystem_ = os; }

std::string Smartphone::getOperatingSystem() const { return operatingSystem_; }

std::string Smartphone::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Model: " + getModel() + "\n";
    info += "Operating system: " + getOperatingSystem() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Operating system: " + getOperatingSystem() + "\n";
    return info;
}

Smartphone::~Smartphone(){}


Tablet::Tablet(int id, double price, int monthPurchase,   Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string os)
        : Electronic(id, price, monthPurchase, supplier, packaging, stock, brand, model), operatingSystem_(os){}

void Tablet::setOperatingSystem(std::string os) { operatingSystem_ = os; }

std::string Tablet::getOperatingSystem() const { return operatingSystem_; }

std::string Tablet::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Model: " + getModel() + "\n";
    info += "Operating system: " + getOperatingSystem() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Operating system: " + getOperatingSystem() + "\n";
    return info;
}

Tablet::~Tablet(){}

