#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>

#include "supplier.h"
#include "stock.h"

class Supplier;

class Product
{
      public:
            Product(int id, double price, Supplier* supplier, int stock);
            Product(int id);//TODO crear este constructor para que busque el producto en la base de datos?
            void setId(int id);
            void setPrice(double price);

            int getId() const;
            double getPrice() const;
            int getStock() const;

            double calculate_discount(int quantity) const;
            virtual void display_product_info()=0;

            bool operator==(const Product& product) const
            {
                  return id_ == product.id_;
            }
      private:
            int id_;
            double price_;
            Supplier* supplier_;     
            Stock* stock_;       
};

class Book: public Product{};
class Game: public Product{};
class Electronic: public Product{};
class Clothing: public Product{};
class Food: public Product{};
class Cosmetic: public Product{};

#endif // PRODUCT_H