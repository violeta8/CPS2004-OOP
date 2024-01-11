#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <iostream>


#include "packaging.hpp"
#include "stock.hpp"
#include "supplier.hpp"

class Product
{
      public:
            Product(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock);
            
            void setId(int id);
            void setPrice(double price);
            void setMonthPurchase(int month);
            void setSupplier(Supplier supplier);
            void setPackaging(Packaging packaging);

            int getId() const;
            double getPrice() const;
            int getMonthPurchase() const;
            Supplier getSupplier() const;
            Packaging getPackaging() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Product();

      private:
            int id_;
            double price_;
            int monthPurchase_;
            Supplier supplier_;
            Packaging packaging_;
            Stock stock_;

};



//* --------------------------------PRODCUT ABSTRACT SUBCLASSES-------------------------------- *//

//* --------------------------------Book abstract (subclass)-------------------------------- *//


//* --------------------------------ComputerGame abstract (subclass)-------------------------------- *//

//* --------------------------------Electronic abstract (subclass)-------------------------------- *//


//* --------------------------------Clothing abstract (subclass)-------------------------------- *//


//* --------------------------------Food abstract (subclass)-------------------------------- *//


//* --------------------------------HomeAppliance abstract (subclass)-------------------------------- *//




//* --------------------------------CONCRETE SUBCLASSES-------------------------------- *//

//* --------------------------------Book concrete subclasses-------------------------------- *//
//* --------------------------------Electronic concrete subclasses-------------------------------- *//
//* --------------------------------Clothing concrete subclasses-------------------------------- *//
//* --------------------------------Food concrete subclasses-------------------------------- *//
//* --------------------------------HomeAppliance concrete subclasses-------------------------------- *//
#endif // PRODUCT_HPP_
