#include "stock.hpp"

Stock::Stock(){}

void Stock::addProduct(Product* product, int units)
{
    stock_[product] += units;
}

void Stock::removeProduct(Product* product, int units)
{
    stock_[product] -= units;
}

void Stock::displayStock() const
{
    for (auto it = stock_.begin(); it != stock_.end(); ++it)
    {
        std::cout << "Product: " << it->first << std::endl;
        std::cout << "Units: " << it->second << std::endl;
    }
}

Stock::~Stock()
{
    for (auto it = stock_.begin(); it != stock_.end(); ++it)
    {
        delete it->first;
    }
}