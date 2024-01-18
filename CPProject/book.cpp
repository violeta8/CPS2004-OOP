#include "book.hpp"

Book::Book(int id, double price, int volume, Supplier supplier) 
      : Product(id, price, volume, supplier){}

double Book::calculate_discount(int quantity, int month)
{
      return Product::calculate_discount(quantity, month);
}

Book::~Book(){}


Novel::Novel(int id, double price, int volume, Supplier supplier) 
      : Book(id, price, volume, supplier){}

std::string Novel::display_product_info()const
{
      std::string info = "[Novel: ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Novel::calculate_discount(int quantity, int month)
{
      return Book::calculate_discount(quantity, month);
}

Novel::~Novel(){}



Textbook::Textbook(int id, double price, int volume, Supplier supplier)
      : Book(id, price, volume, supplier){}

std::string Textbook::display_product_info() const
{
      std::string info = "[Textbook, ";
      info += "ID: " + std::to_string(getId()) + ", ";
      info += "Supplier: " + getSupplier().getName() + ", ";
      info += "Price: " + std::to_string(getPrice()) + "]";
      return info;
}

double Textbook::calculate_discount(int quantity, int month)
{
      return Book::calculate_discount(quantity, month);
}

Textbook::~Textbook(){}
