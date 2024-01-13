#ifndef ELECTRONIC_HPP_
#define ELECTRONIC_HPP_

#include "product.hpp"

class Electronic : public Product
{
      public:
            Electronic(int id, double price, int volume, std::string brand);
            
            std::string getBrand() const;

            void updateProduct(std::string what, std::string change)override;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Electronic();

      private:
            std::string brand_;
};


class Smartphone : public Electronic
{
public:
    Smartphone(int id, double price, int volume, std::string brand, std::string operatingSystem);

    std::string getOperatingSystem() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~Smartphone();

private:
    std::string operatingSystem_;
};

class Tablet : public Electronic
{
public:
    Tablet(int id, double price, int volume, std::string brand, std::string model);
    
    std::string getModel() const;

    void updateProduct(std::string what, std::string change)override;

    std::string display_product_info();

    ~Tablet();

private:
    std::string model_;
};


#endif // ELECTRONIC_HPP_