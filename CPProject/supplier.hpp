#ifndef SUPPLIER_HPP_
#define SUPPLIER_HPP_

#include <iostream>
#include <list>
#include "product.hpp"


class Supplier
{
      public:
            Supplier(std::string name, std::string address, std::string phone, std::string email);
            void setName(std::string name);
            void setAddress(std::string address);
            void setPhone(std::string phone);
            void setEmail(std::string email);

            std::string getName() const;
            std::string getAddress() const;
            std::string getPhone() const;
            std::string getEmail() const;

            void addProduct(Product& product);//todo & ok?
            void removeProduct(Product& product);

            friend std::ostream& operator<< (std::ostream& os, const Supplier& supplier);

            ~Supplier();

      private:
            std::string name_;
            std::string address_;
            std::string phone_;
            std::string email_;
            std::list<Product> products_;
};

#endif // SUPPLIER_HPP_