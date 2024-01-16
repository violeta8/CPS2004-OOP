#ifndef FOOD_HPP_
#define FOOD_HPP_

#include "product.hpp"

class Food : public Product
{
      public:
            Food(int id, double price, int volume, Supplier supplier);

            virtual std::string display_product_info()const=0;
            virtual double calculate_discount(int quantity, int month);

            ~Food();
};


//* --------------------------------Food concrete subclasses-------------------------------- *//
class Milk : public Food
{
public:
    Milk(int id, double price, int volume, Supplier supplier);

    std::string display_product_info() const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Milk();
};

class Cheese : public Food
{
public:
    Cheese(int id, double price, int volume, Supplier supplier);
        
    std::string display_product_info()const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Cheese();
};

#endif // FOOD_HPP