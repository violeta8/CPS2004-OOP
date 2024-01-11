#ifndef PACKAGING_H
#define PACKAGING_H

#include <iostream>
#include <string>
#include <vector>

#include "product.h"
class Packaging
{
      public:
            Packaging(int capacity, double cost);

            void setCapacity(int capacity);
            void setCost(double cost);
            void addProduct(Product* product, int quantity);
            void removeProduct(Product* product);

            int getCapacity() const;
            double getCost() const;
            size_t getActualCapacity() const;
      private:
            int capacity_;
            double cost_;
            std::vector<Product*> product_;
};

#endif // PACKAGING_H