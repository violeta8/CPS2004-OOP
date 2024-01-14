#ifndef HOMEAPPLIANCE_HPP_
#define HOMEAPPLIANCE_HPP_

#include "product.hpp"

class HomeAppliance : public Product
{
      public:
            HomeAppliance(int id, double price, int volume, Supplier supplier, std::string brand);
            
            std::string getBrand() const;

            virtual void updateProduct(std::string what, std::string change)override;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~HomeAppliance();

      private:
            std::string brand_;
};

class Fridge : public HomeAppliance
{
public:
    Fridge(int id, double price, int volume, Supplier supplier, std::string brand, std::string model);
    
    std::string getModel() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~Fridge();

private:
    std::string model_;
};

class WashingMachine : public HomeAppliance
{
public:
    WashingMachine(int id, double price, int volume, Supplier supplier, std::string brand, std::string energyEfficiency);
    
    std::string getEnergyEfficiency() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~WashingMachine();

private:
    std::string energyEfficiency_;
};

#endif // HOMEAPPLIANCE_HPP_