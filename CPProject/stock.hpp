#ifndef STOCK_HPP_
#define STOCK_HPP_

#include <iostream>

#include "product.hpp"

class Product;

class Stock
{
      public:
            Stock(Product* product, int units);
            void addProduct(Product* product, int units);
            void removeProduct();
            void updateStock(int units);
            Product* getProduct() const;
            int getUnits() const;

            std::string display_stock_info()const;

            friend bool operator==(const Stock& stock1, const Stock& stock2);

            ~Stock();

      private:
            Product* product_;
            int units_;
};

#endif // STOCK_HPP_