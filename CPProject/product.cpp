#include "product.hpp"

//* --------------------------------Product abstract class-------------------------------- *//
Product::Product(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock) 
      : id_(id), price_(price), monthPurchase_(monthPurchase), supplier_(supplier), packaging_(packaging), stock_(stock){}

void Product::setId(int id) { id_ = id; }

void Product::setSupplier(Supplier supplier) { supplier_ = supplier; }

void Product::setPackaging(Packaging packaging) { packaging_ = packaging; }

int Product::getId() const { return id_; }

double Product::getPrice() const { return price_; }

Packaging Product::getPackaging() const{ return packaging_; }

double Product::calculate_discount(int quantity) const
{
      double discount;
      if(quantity >= 10 && quantity < 50)
      {
            discount =  0.05 + monthPurchase_ / 100.0;            
      }
      else if(quantity >= 50 && quantity < 100)
      {
            discount = 0.1 + monthPurchase_ / 100.0;
      }
      else if(quantity >= 100)
      {
            discount = 0.15 + monthPurchase_ / 100.0;
      }
      else
      {
            discount = monthPurchase_ / 100.0;
      }
      return discount;

}

Product::~Product(){}

//* --------------------------------PRODUCT ABSTRACT SUBCLASSES-------------------------------- *//

//* --------------------------------Book abstract (subclass)-------------------------------- *//


//* --------------------------------ComputerGame abstrat (subclass)-------------------------------- *//


//* --------------------------------Electronic abstract (subclass)-------------------------------- *//

//* --------------------------------Clothing abstract (subclass)-------------------------------- *//


//* --------------------------------Food abstract (subclass)-------------------------------- *//


//* --------------------------------HomeAppliance abstract (subclass)-------------------------------- *//


//* --------------------------------PRODUCT CONCRETE SUBCLASSES-------------------------------- *//

//* --------------------------------Book concrete subclasses-------------------------------- *//






