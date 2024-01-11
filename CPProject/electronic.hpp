#ifndef ELECTRONIC_HPP_
#define ELECTRONIC_HPP_

#include "product.hpp"

class Electronic : public Product
{
      public:
            Electronic(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model);
            
            void setBrand(std::string brand);
            void setModel(std::string model);
            
            std::string getBrand() const;
            std::string getModel() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Electronic();

      private:
            std::string brand_;
            std::string model_;
};


class Smartphone : public Electronic
{
public:
    Smartphone(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string operatingSystem);

    void setOperatingSystem(std::string operatingSystem);

    std::string getOperatingSystem() const;

    std::string display_product_info();

    ~Smartphone();

private:
    std::string operatingSystem_;
};

class Tablet : public Electronic
{
public:
    Tablet(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string brand, std::string model, std::string operatingSystem);
    std::string getOperatingSystem() const;

    std::string display_product_info();

    ~Tablet();

private:
    std::string operatingSystem_;
};


#endif // ELECTRONIC_HPP_