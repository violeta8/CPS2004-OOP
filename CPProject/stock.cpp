#include "stock.hpp"

Stock::Stock(Product& product, int units)
{
    product_ = &product;
    units_ = units;
}

void Stock::addProduct(Product& product, int units)
{
    product_ = &product;
    units_ = units;
}

void Stock::removeProduct()
{
    product_ = nullptr;
    units_ = 0;
}

void Stock::updateStock(int units)
{
    units_ = units;
}

Product& Stock::getProduct() const
{
    return *product_;
}

int Stock::getUnits() const
{
    return units_;
}

Stock::~Stock()
{
    product_ = nullptr;
    units_ = 0;
}

std::string Stock::display_stock_info()const
{
    std::string info = "";
    info += "Product: " + std::to_string(product_->getId())+ "\n";
    info += "Units: " + std::to_string(units_) + "\n";
    return info;
}