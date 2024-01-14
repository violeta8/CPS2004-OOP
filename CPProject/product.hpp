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

            virtual void updateProduct(std::string what, std::string change);

            virtual std::string display_product_info()const=0;
            double calculate_discount(int quantity, int month) const;

            ~Product();

      private:
            int id_;//get this incremented
            double price_;
            int volume_;
            Supplier supplier_;
};

#endif // PRODUCT_HPP_
