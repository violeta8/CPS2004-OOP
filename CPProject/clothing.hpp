#ifndef CLOTHING_HPP_
#define CLOTHING_HPP_

#include "product.hpp"

class Clothing : public Product
{
      public:
            Clothing(int id, double price, int volume, Supplier supplier,std::string colour);
            
            std::string getColour() const;

            void updateProduct(std::string what, std::string change)override;
            
            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Clothing();
      private:
            std::string colour_;
};

class TShirt : public Clothing
{
public:
    TShirt(int id, double price, int volume, Supplier supplier,std::string colour, std::string size);

    std::string getSize() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~TShirt();

private:
    std::string size_;
};

class Pants : public Clothing
{
public:
    Pants(int id, double price, int volume, Supplier supplier, std::string colour, std::string shop);
    
    std::string getShop() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~Pants();

private:
    std::string shop_;

};


#endif // CLOTHING_HPP_