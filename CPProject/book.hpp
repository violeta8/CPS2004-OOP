#ifndef BOOK_HPP_
#define BOOK_HPP_

#include "product.hpp"
#include "fecha.hpp"

class Book : public Product
{
      public:
            Book(int id, double price, int volume, Supplier supplier);

            virtual std::string display_product_info()const=0;
            virtual double calculate_discount(int quantity, int month);

            ~Book();
};

class Novel : public Book
{
      public:
            Novel(int id, double price, int volume, Supplier supplier);
            
            virtual std::string display_product_info()const override;
            virtual double calculate_discount(int quantity, int month) override;

            ~Novel();
};

class Textbook : public Book
{
      public:
            Textbook(int id, double price, int volume, Supplier supplier);
            
            virtual std::string display_product_info()const override;
            virtual double calculate_discount(int quantity, int month) override;

            ~Textbook();
};


#endif // BOOK_HPP_