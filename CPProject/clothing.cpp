#include "clothing.hpp"

Clothing::Clothing(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string size, std::string colour)
      : Product(id, price, monthPurchase, supplier, packaging, stock), brand_(brand), colour_(colour){}

void Clothing::setBrand(std::string brand) { brand_ = brand; }

void Clothing::setColour(std::string color) { colour_ = color; }

std::string Clothing::getBrand() const { return brand_; }

std::string Clothing::getColour() const { return colour_; }

Clothing::~Clothing(){}


//* --------------------------------Clothing concrete subclasses-------------------------------- *//
TShirt::TShirt(int id, double price, int monthPurchase,   Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string color, std::string size)
        : Clothing(id, price, monthPurchase, supplier, packaging, stock, brand, color), size_(size){}

void TShirt::setSize(std::string size) { size_ = size; }

std::string TShirt::getSize() const { return size_; }

std::string TShirt::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Color: " + getColor() + "\n";
    info += "Size: " + getSize() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Size: " + getSize() + "\n";
    return info;
}

TShirt::~TShirt(){}


Pants::Pants(int id, double price, int monthPurchas Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string color, std::string size)
        : Clothing(id, price, monthPurchase, supplier, packaging, stock, brand, color), size_(size){}

void Pants::setSize(std::string size) { size_ = size; }

std::string Pants::getSize() const { return size_; }

std::string Pants::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Brand: " + getBrand() + "\n";
    info += "Color: " + getColor() + "\n";
    info += "Size: " + getSize() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Size: " + getSize() + "\n";
    return info;
}

Pants::~Pants(){}

