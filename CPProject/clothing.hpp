#ifndef CLOTHING_HPP_
#define CLOTHING_HPP_

#include "product.hpp"

class Clothing : public Product
{
    public:
        Clothing(int id, double price, int volume, Supplier supplier);
                    
        virtual std::string display_product_info()const=0;
        virtual double calculate_discount(int quantity);

        ~Clothing();
};

class TShirt : public Clothing
{
public:
    TShirt(int id, double price, int volume, Supplier supplier);

    virtual std::string display_product_info()const=0;
    virtual double calculate_discount(int quantity);

    ~TShirt();
};

class Pants : public Clothing
{
public:
    Pants(int id, double price, int volume, Supplier supplier,, std::string shop);
    
    virtual std::string display_product_info()const=0;
    virtual double calculate_discount(int quantity);
    ~Pants();

};


#endif // CLOTHING_HPP_