#ifndef CLOTHING_HPP_
#define CLOTHING_HPP_

#include "product.hpp"

class Clothing : public Product
{
      public:
            Clothing(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string size, std::string colour);
            
            void setBrand(std::string brand);
            void setColour(std::string colour);
            
            std::string getBrand() const;
            std::string getColour() const;
            
            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Clothing();
      private:
            std::string brand_;
            std::string colour_;
};

class TShirt : public Clothing
{
public:
    TShirt(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string size, std::string colour, std::string type);
    std::string getSize() const;
    std::string getColor() const;

    std::string display_product_info();

    ~TShirt();

private:
    std::string size_;
};

class Pants : public Clothing
{
public:
    Pants(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string size, std::string colour, std::string type);
    std::string getSize() const;
    std::string getColor() const;

    std::string display_product_info();

    ~Pants();

private:
    std::string size_;

};


#endif // CLOTHING_HPP_