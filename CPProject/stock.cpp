#include "stock.hpp"

Stock::Stock(Product* product, int units) : product_(product), units_(units){}

void Stock::addProduct(Product* product, int units)
{
    product_ = product;
    units_ = units;
}

void Stock::removeProduct()
{
    units_ = 0;
}

void Stock::updateStock(int units)
{
    units_ = units;
}

Product* Stock::getProduct() const
{
    return product_;
}

int Stock::getUnits() const
{
    return units_;
}

Stock::~Stock()
{
    units_ = 0;
}

std::string Stock::display_stock_info()const
{
    std::string info = "";
    info += "[Product ID: " + std::to_string(product_->getId())+ ", ";
    info += "Units: " + std::to_string(units_) + "]";
    return info;
}

bool operator==(const Stock& stock, const Stock& stock2) 
{
    return (stock.getProduct() == stock2.getProduct());
}