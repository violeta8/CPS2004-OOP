#include "packaging.hpp"

Packaging::Packaging(int units, double price, double volume, double weight)
{
    units_ = units;
    pricePerUnit_ = price;
    volume_ = volume;
    weight_ = weight;
}

//* ----------------Setters and getters---------------- *//
void Packaging::setUnits(int units)
{
    units_ = units;
}

void Packaging::setPrice(double price)
{
    pricePerUnit_ = price;
}

void Packaging::setVolume(double volume)
{
    volume_ = volume;
}

void Packaging::setWeight(double weight)
{
    weight_ = weight;
}

int Packaging::getUnits() const
{
    return units_;
}

double Packaging::getPrice() const
{
    return pricePerUnit_;
}

double Packaging::getVolume() const
{
    return volume_;
}

double Packaging::getWeight() const
{
    return weight_;
}


void Packaging::display_info() const
{
    std::cout << "Units: " << getUnits() << std::endl;
    std::cout << "Price: " << getPrice() << std::endl;
    std::cout << "Volume: " << getVolume() << std::endl;
    std::cout << "Weight: " << getWeight() << std::endl;
}

Packaging::~Packaging(){}