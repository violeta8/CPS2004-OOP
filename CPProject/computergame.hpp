#ifndef COMPUTERGAME_HPP
#define COMPUTERGAME_HPP

#include "product.hpp"

class ComputerGame : public Product
{
      public:
            ComputerGame(int id, double price, int volume, Supplier supplier, int ageLimit);
            
            int getAgeLimit() const;

            void updateProduct(std::string what, std::string change)override;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~ComputerGame();

      private:
            int ageLimit_;
};




//* --------------------------------ComputerGame concrete subclasses-------------------------------- *//
class Zelda : public ComputerGame
{
public:
    Zelda(int id, double price, int volume, Supplier supplier, int ageLimit, std::string platform);

    std::string getPlatform() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~Zelda();

private:
    std::string platform_;
};

class Minecraft : public ComputerGame
{
public:
    Minecraft(int id, double price, int volume, Supplier supplier, int ageLimit, std::string platform);
    
    std::string getPlatform() const;
    
    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~Minecraft();

private:
    std::string platform_;
};


#endif // COMPUTERGAME_HPP