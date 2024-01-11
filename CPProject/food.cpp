#include "food.hpp"
#include "product.hpp"

Food::Food(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, Fecha expirationDate) 
      : Product(id, price, monthPurchase, supplier, packaging, stock), expirationDate_(expirationDate){}

void Food::setExpirationDate(Fecha expirationDate) { expirationDate_ = expirationDate; }

Fecha Food::getExpirationDate() const { return expirationDate_; }

Food::~Food(){}


//* --------------------------------Food concrete subclasses-------------------------------- *//
Milk::Milk(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, Fecha expirationDate, std::string getFatContent)
        : Food(id, price, monthPurchase, supplier, packaging, stock, expirationDate), fatContent_(getFatContent){}

std::string Milk::getFatContent() const { return fatContent_; }

std::string Milk::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Expiration date: " + std::to_string(getExpirationDate()) + "\n";//todo mirar si esto ta bien
    info += "Fat content: " + getFatContent() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Fat content: " + getFatContent() + "\n";
    return info;
}

Milk::~Milk(){}


Cheese::Cheese(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, Fecha expirationDate, std::string getFatContent, std::string type)
        : Food(id, price, monthPurchase, supplier, packaging, stock, expirationDate), fatContent_(getFatContent), type_(type){}

void Cheese::setFatContent(std::string fatContent) { fatContent_ = fatContent; }

void Cheese::setType(std::string type) { type_ = type; }

std::string Cheese::getFatContent() const { return fatContent_; }

std::string Cheese::getType() const { return type_; }

std::string Cheese::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Expiration date: " + std::to_string(getExpirationDate()) + "\n";//todo mirar si esto ta bien
    info += "Fat content: " + getFatContent() + "\n";
    info += "Type: " + getType() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Fat content: " + getFatContent() + "\n";
    info += "Type: " + getType() + "\n";
    return info;
}

Cheese::~Cheese(){}


