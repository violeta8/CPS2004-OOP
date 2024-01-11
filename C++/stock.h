#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>

#include "product.h"

class Stock
{
      public:
            Stock(int capacity);
            void addProduct();
            void removeProduct();

            int getStock() const;
      private:
            int capacity_;
};

#endif // STOCK_H