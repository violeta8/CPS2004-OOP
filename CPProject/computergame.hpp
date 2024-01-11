#ifndef COMPUTERGAME_HPP
#define COMPUTERGAME_HPP

#include "product.hpp"

class ComputerGame : public Product
{
      public:
            ComputerGame(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string title, int ageLimit);
            
            void setTitle(std::string title);
            void setAgeLimit(int ageLimit);
            
            std::string getTitle() const;
            int getAgeLimit() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~ComputerGame();

      private:
            std::string title_;
            int ageLimit_;
};




//* --------------------------------ComputerGame concrete subclasses-------------------------------- *//
class Zelda : public ComputerGame
{
public:
    Zelda(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string title, int ageLimit, std::string platform);

    void setPlatform(std::string platform);

    std::string getPlatform() const;

    std::string display_product_info();

    ~Zelda();

private:
    std::string platform_;
};

class Minecraft : public ComputerGame
{
public:
    Minecraft(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string title, int ageLimit, std::string platform);
    std::string getPlatform() const;

    std::string display_product_info();

    ~Minecraft();

private:
    std::string platform_;
};


#endif // COMPUTERGAME_HPP