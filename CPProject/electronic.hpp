#ifndef ELECTRONIC_HPP
#define ELECTRONIC_HPP

#include "product.hpp"

class Electronic : public Product
{
      public:
            Electronic(int id, double price, int volume, Supplier supplier);

            virtual std::string display_product_info()const=0;
            virtual double calculate_discount(int quantity, int month);

            ~Electronic();
};


//* --------------------------------Electronic concrete subclasses-------------------------------- *//
class Tablet : public Electronic
{
public:
    Tablet(int id, double price, int volume, Supplier supplier);

    std::string display_product_info() const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Tablet();
};

class Smartphone : public Electronic
{
public:
    Smartphone(int id, double price, int volume, Supplier supplier);
        
    std::string display_product_info()const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Smartphone();
};


#endif // ELECTRONIC_HPP