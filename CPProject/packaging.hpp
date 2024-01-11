#ifndef PACKAGING_HPP_
#define PACKAGING_HPP_

#include <iostream>

// #include "product.hpp" //todo no se si esto esta bien

//class that will be used to store the packaging information of the product
class Packaging
{
      public:
            Packaging(int units, double price, double volume, double weight);
            void setUnits(int units);
            void setPrice(double price);
            void setVolume(double volume);
            void setWeight(double weight);
            int getUnits() const;
            double getPrice() const;
            double getVolume() const;
            double getWeight() const;

            void display_info() const;
            ~Packaging();

      private:
            int units_;
            double pricePerUnit_;
            double volume_;
            double weight_;
};

#endif // PACKAGING_HPP_