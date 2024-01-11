#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream>
#include <string>
#include <vector>

#include "product.h"
class Product;

class Supplier
{
      private:
            int id_;
            std::string name_;
            std::string email_;
            std::string password_;
            std::string credit_card_;
            std::vector<Product*> products_; 

      public:
            Supplier(int id, std::string name, std::string email, std::string password, std::string credit_card);
            void setId(int id);
            void setName(std::string name);
            void setEmail(std::string email);
            void setPassword(std::string password);
            void setCreditCard(std::string credit_card);

            int getId() const;
            std::string getName() const;
            std::string getEmail() const;
            std::string getPassword() const;
            std::string getCreditCard() const;
            std::vector<Product*> getProducts() const;
};

#endif // SUPPLIER_H