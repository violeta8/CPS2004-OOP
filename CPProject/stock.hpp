#ifndef STOCK_HPP_
#define STOCK_HPP_

#include <iostream>
#include <map>

#include "product.hpp"

class Product;

class Stock
{
      public:
            Stock(Product product, int units);
            void addProduct(Product* product, int units);
            void removeProduct(Product* product, int units);
            void displayStock() const;
            ~Stock();

      private:
            Product product_;
            int units_;
};

#endif // STOCK_HPP_