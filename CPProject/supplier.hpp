#ifndef SUPPLIER_HPP_
#define SUPPLIER_HPP_

#include <iostream>
#include <list>

class Supplier
{
      public:
            Supplier(std::string name, std::string address, std::string phone, std::string email);
            
            void setName(std::string name);
            void setAddress(std::string address);
            void setPhone(std::string phone);
            void setEmail(std::string email);

            int getId()const;
            std::string getName() const;
            std::string getAddress() const;
            std::string getPhone() const;
            std::string getEmail() const;
            
            std::string display_supplier_info()const;

            ~Supplier();

      private:
            int id_;
            std::string name_;
            std::string address_;
            std::string phone_;
            std::string email_;
};

#endif // SUPPLIER_HPP_