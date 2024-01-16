#ifndef HOMEAPPLIANCE_HPP_
#define HOMEAPPLIANCE_HPP_

#include "product.hpp"

class HomeAppliance : public Product
{
      public:
            HomeAppliance(int id, double price, int volume, Supplier supplier);

            virtual std::string display_product_info()const=0;
            virtual double calculate_discount(int quantity, int month);

            ~HomeAppliance();
};


//* --------------------------------HomeAppliance concrete subclasses-------------------------------- *//
class Fridge : public HomeAppliance
{
public:
    Fridge(int id, double price, int volume, Supplier supplier);

    std::string display_product_info() const;
    virtual double calculate_discount(int quantity, int month) override;

    ~Fridge();
};

class WashingMachine : public HomeAppliance
{
public:
    WashingMachine(int id, double price, int volume, Supplier supplier);
        
    std::string display_product_info()const;
    virtual double calculate_discount(int quantity, int month) override;

    ~WashingMachine();
};

#endif // HOMEAPPLIANCE_HPP_