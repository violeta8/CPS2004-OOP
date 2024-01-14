#include "food.hpp"
#include "product.hpp"

Food::Food(int id, double price, int volume, Supplier supplier, std::string expirationDate) 
      : Product(id, price, volume, supplier), expirationDate_(expirationDate){}


std::string Food::getExpirationDate() const { return expirationDate_; }

Food::~Food(){}


//* --------------------------------Food concrete subclasses-------------------------------- *//
Milk::Milk(int id, double price, int volume, Supplier supplier, std::string expirationDate, std::string getFatContent)
        : Food(id, price, volume, supplier, expirationDate), fatContent_(getFatContent){}

std::string Milk::getFatContent() const { return fatContent_; }

std::string Milk::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Expiration date: " + getExpirationDate() + "\n";//todo mirar si esto ta bien
    info += "Fat content: " + getFatContent() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

Milk::~Milk(){}


Cheese::Cheese(int id, double price, int volume, Supplier supplier, std::string expirationDate, std::string type)
        : Food(id, price, volume, supplier, expirationDate), type_(type){}

std::string Cheese::getType() const { return type_; }

std::string Cheese::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Expiration date: " + getExpirationDate() + "\n";//todo mirar si esto ta bien
    info += "Type: " + getType() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

Cheese::~Cheese(){}


