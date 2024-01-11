#ifndef FOOD_HPP_
#define FOOD_HPP_

#include "product.hpp"
#include "fecha.hpp"

class Food : public Product
{
      public:
            Food(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, Fecha expirationDate);
            void setExpirationDate(Fecha expirationDate);
            Fecha getExpirationDate() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Food();

      private:
            Fecha expirationDate_;
};


class Milk : public Food
{
public:
    Milk(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, Fecha expirationDate, std::string fatContent);
    std::string getFatContent() const;

    std::string display_product_info();

    ~Milk();

private:
    std::string fatContent_;
};

class Cheese : public Food
{
public:
    Cheese(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, Fecha expirationDate, std::string fatContent, std::string type);

    void setFatContent(std::string fatContent);
    void setType(std::string type);

    std::string getFatContent() const;
    std::string getType() const;

    std::string display_product_info();

    ~Cheese();

private:
    std::string fatContent_;
    std::string type_;
};


#endif // FOOD_HPP_