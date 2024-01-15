#include "book.hpp"

Book::Book(int id, double price, int volume, Supplier supplier) 
      : Product(id, price, volume, supplier){}

double Book::calculate_discount(int quantity, int month)
{
      Product::calculate_discount(quantity, month);
}

Book::~Book(){}


Novel::Novel(int id, double price, int volume, Supplier supplier) 
      : Book(id, price, volume, supplier){}

std::string Novel::display_product_info()const
{
      std::string info = "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double Novel::calculate_discount(int quantity, int month)
{
      Book::calculate_discount(quantity, month);
}

Novel::~Novel(){}



Textbook::Textbook(int id, double price, int volume, Supplier supplier)
      : Book(id, price, volume, supplier){}

std::string Textbook::display_product_info() const
{
      std::string info = "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double Textbook::calculate_discount(int quantity, int month)
{
      Book::calculate_discount(quantity, month);
}

Textbook::~Textbook(){}
