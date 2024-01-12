#ifndef FOOD_HPP_
#define FOOD_HPP_

#include "product.hpp"

class Food : public Product
{
      public:
            Food(int id, double price, std::string expirationDate);

            std::string getExpirationDate() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Food();

      private:
            std::string expirationDate_;
};


class Milk : public Food
{
public:
    Milk(int id, double price, std::string expirationDate, std::string fatContent);
    std::string getFatContent() const;

    std::string display_product_info();

    ~Milk();

private:
    std::string fatContent_;
};

class Cheese : public Food
{
public:
    Cheese(int id, double price, std::string expirationDate, std::string type);

    void setFatContent(std::string fatContent);
    void setType(std::string type);

    std::string getFatContent() const;
    std::string getType() const;

    std::string display_product_info();

    ~Cheese();

private:
    std::string type_;
};


#endif // FOOD_HPP_