#ifndef PACKAGING_HPP_
#define PACKAGING_HPP_

#include <iostream>
#include <list>
#include <map>

#include "product.hpp" 
#include "transport.hpp"
#include "fecha.hpp"

//class that will be used to store the packaging information of the product
class Packaging
{
      public:
            Packaging(Transport* t);

            void setCapacity(int capacity);
            void setCost(double cost);

            int getCapacity() const;
            double getCost() const;

            double getTotalCost() const;

            std::string display_packaging_info() const;
            ~Packaging();

      private:
            int capacity_;
            double cost_;
            std::list<Product*> products_;
            std::map<Product*, int> product_quantity_;


};

#endif // PACKAGING_HPP_