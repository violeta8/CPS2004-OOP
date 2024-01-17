#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <iostream>
#include "supplier.hpp"

class Product 
{
      public:
            Product(int id, double price, int volume, Supplier supplier);
            
            void setId(int id);
            void setPrice(double price);
            void setVolume(int volume);

            int getId() const;
            double getPrice() const;
            int getVolume() const;
            Supplier getSupplier() const;

            void updateProduct(std::string what, std::string change);

            virtual std::string display_product_info()const=0;
            virtual double calculate_discount(int quantity, int month);

            friend bool operator==(const Product& product, const Product& product2);

            ~Product();

      private:
            int id_;
            double price_;
            int volume_;
            Supplier supplier_;
};

#endif // PRODUCT_HPP_
