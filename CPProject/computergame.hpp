#ifndef COMPUTERGAME_HPP
#define COMPUTERGAME_HPP

#include "product.hpp"

class ComputerGame : public Product
{
      public:
            ComputerGame(int id, double price, int volume, Supplier supplier);

            virtual std::string display_product_info()const=0;
            virtual double calculate_discount(int quantity, int month);

            ~ComputerGame();
};




//* --------------------------------ComputerGame concrete subclasses-------------------------------- *//
class Zelda : public ComputerGame
{
public:
    Zelda(int id, double price, int volume, Supplier supplier);

    std::string display_product_info() const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Zelda();
};

class Minecraft : public ComputerGame
{
public:
    Minecraft(int id, double price, int volume, Supplier supplier);
        
    std::string display_product_info()const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Minecraft();
};


#endif // COMPUTERGAME_HPP