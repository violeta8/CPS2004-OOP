#include "packaging.h"

Packaging::Packaging(int capacity, double cost) : capacity_(capacity), cost_(cost){}

void Packaging::setCapacity(int capacity){ capacity_ = capacity; }
void Packaging::setCost(double cost){ cost_ = cost; }
void Packaging::addProduct(Product* product, int quantity)
{
      if(product_.size() < capacity_)
      {
            for(int i = 0; i < quantity; i++)
                  product_.push_back(product);
      }
}
void Packaging::removeProduct(Product* product)
{
      for(int i = 0; i < product_.size(); i++)
      {
            if(product_[i] == product)
            {
                  product_.erase(product_.begin()+i);
            }
      }      
}

int Packaging::getCapacity() const{ return product_.size(); }
double Packaging::getCost() const
{
      return cost_*product_.size();
}
size_t Packaging::getActualCapacity() const{ return product_.size(); }