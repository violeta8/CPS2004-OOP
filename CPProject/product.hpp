#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <iostream>


#include "packaging.hpp"
#include "stock.hpp"
#include "supplier.hpp"

class Product 
{
      public:
            Product(int id, double price);
            
            void setId(int id);
            void setPrice(double price);

            int getId() const;
            double getPrice() const;

            virtual void updateProduct(std::string what, std::string change);

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity, int month) const;

            ~Product();

      private:
            int id_;//get this incremented
            double price_;
};

#endif // PRODUCT_HPP_
