#ifndef HOMEAPPLIANCE_HPP_
#define HOMEAPPLIANCE_HPP_

#include "product.hpp"

class HomeAppliance : public Product
{
      public:
            HomeAppliance(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model);
            
            void setBrand(std::string brand);
            void setModel(std::string model);
            
            std::string getBrand() const;
            std::string getModel() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~HomeAppliance();

      private:
            std::string brand_;
            std::string model_;
};



class Fridge : public HomeAppliance
{
public:
    Fridge(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string energyEfficiency);
    std::string getEnergyEfficiency() const;

    std::string display_product_info();

    ~Fridge();

private:
    std::string energyEfficiency_;
};

class WashingMachine : public HomeAppliance
{
public:
    WashingMachine(int id, double price, int monthPurchase, bool automatic, Supplier supplier, Packaging packaging, std::string brand, std::string model, std::string energyEfficiency);
    std::string getEnergyEfficiency() const;
    bool getIsAutomatic() const;

    std::string display_product_info();

    ~WashingMachine();

private:
    std::string energyEfficiency_;
    bool isAutomatic_;
};


#endif // HOMEAPPLIANCE_HPP_