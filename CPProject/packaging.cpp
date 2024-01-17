#include "packaging.hpp"

Packaging::Packaging(Transport* t)
{
    products_ = std::list<Product*>();
    product_quantity_ = std::map<Product*, int>();
    if(dynamic_cast<Truck*>(t) != nullptr)
    {
        capacity_ = 50;
        cost_ = 3;
    }
    else if(dynamic_cast<Ship*>(t) != nullptr)
    {
        capacity_ = 80;
        cost_ = 1;
    }
    else if(dynamic_cast<Plane*>(t) != nullptr)
    {
        capacity_ = 100;
        cost_ = 2;
    }
}

//* ----------------Setters and getters---------------- *//
void Packaging::setCapacity(int capacity)
{
    capacity_ = capacity;
}

void Packaging::setCost(double cost)
{
    cost_ = cost;
}

int Packaging::getCapacity() const
{
    return capacity_;
}

double Packaging::getCost() const
{
    return cost_;
}

double Packaging::getTotalCost() const
{
    double result=0;
    for(std::list<Product*>::const_iterator it = products_.begin(); it != products_.end(); ++it)
    {
        result += (*it)->getPrice()*(*it)->calculate_discount(product_quantity_.at(*it), Fecha().mes());
    }
    if(capacity_ < 50)
    {
        return result + cost_;
    }
    else if(capacity_ < 80)
    {
        return result + cost_;
    }
    else
    {
        return result + cost_;
    }
}

std::string Packaging::display_packaging_info() const
{
    std::string info = "[Packaging:  Capacity: " + std::to_string(capacity_) + ", Total Cost: " + std::to_string(getTotalCost()) + ", Products: \n{"; 
    for(std::list<Product*>::const_iterator it = products_.begin(); it != products_.end(); ++it)
    {
        info += (*it)->display_product_info();
    }
    "}\n";
    return info;
}



Packaging::~Packaging(){}