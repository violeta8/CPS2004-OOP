#ifndef BOOK_HPP_
#define BOOK_HPP_

#include "product.hpp"
#include "fecha.hpp"

class Book : public Product
{
      public:
            Book(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string author, std::string title, std::string genre, int pages);
            
            void setAuthor(std::string author);
            void setTitle(std::string title);
            void setGenre(std::string genre);
            void setPages(int pages);

            std::string getAuthor() const;
            std::string getTitle() const;
            std::string getGenre() const;
            int getPages() const;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Book();

      private:
            std::string author_;
            std::string title_;
            std::string genre_;
            int pages_;
};

class Novel : public Book
{
      public:
            Novel(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string author, std::string title, std::string genre, int pages, Fecha publicationDate);
            
            Fecha getPublicationDate() const;

            std::string display_product_info();

            ~Novel();

      private:
            Fecha publicationDate_;
};

class Textbook : public Book
{
      public:
            Textbook(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string author, std::string title, std::string genre, int pages, std::string subject);
            
            std::string getSubject() const;

            std::string display_product_info();

            ~Textbook();

      private:
            std::string subject_;
};


#endif // BOOK_HPP_