#include "product.h"

Product::Product(int id, double price, Supplier* supplier, int stock) : id_(id), price_(price), supplier_(supplier)
{
      stock_ = new Stock(stock);
}

void Product::setId(int id){ id_ = id; }
void Product::setPrice(double price){ price_ = price; }

int Product::getId() const{ return id_; }
double Product::getPrice() const{ return price_; }
int Product::getStock() const{ return stock_->getStock(); }

double Product::calculate_discount(int quantity) const
{
      if(quantity < 10) return 1.0;//no discount
      else if(quantity <= 50 && quantity >10) return 0.05;
      else if(quantity > 50 && quantity <=100) return 0.09;
      else return 0.125;
}

void Product::display_product_info()
{
      std::cout << "Product ID: " << id_ << std::endl;
      std::cout << "Price: " << price_ << std::endl;
      std::cout << "Supplier: " << supplier_->getName() << std::endl;
      std::cout << "Stock: " << stock_->getStock() << std::endl;
}