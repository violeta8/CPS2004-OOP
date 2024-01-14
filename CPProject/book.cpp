#include "book.hpp"

Book::Book(int id, double price, int volume, Supplier supplier,std::string title) 
      : Product(id, price, volume, supplier), title_(title){}

void Book::setTitle(std::string title) { title_ = title; }

std::string Book::getTitle() const { return title_; }

void Book::updateProduct(std::string what, std::string change) 
{
      if (what == "price")
      {
            setPrice(std::stod(change));
      }
}

Book::~Book(){}


Novel::Novel(int id, double price, int volume, Supplier supplier,std::string title, std::string genre) 
      : Book(id, price, volume, supplier, title), genre_(genre){}

std::string Novel::getGenre() const { return genre_; }

void Novel::updateProduct(std::string what, std::string change)
{
      if (what == "genre")
      {
            genre_ = change;
      }
}

std::string Novel::display_product_info()
{
      std::string info = "ID: " + std::to_string(getId()) + "\n";
      info += "Title: " + getTitle() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      info += "Genre: " + getGenre() + "\n";
      return info;
}

Novel::~Novel(){}



Textbook::Textbook(int id, double price, int volume, Supplier supplier,std::string title, std::string subject)
      : Book(id, price, volume, supplier, title), subject_(subject){}

std::string Textbook::getSubject() const { return subject_; }

void Textbook::updateProduct(std::string what, std::string change)
{
      if (what == "subject")
      {
            subject_ = change;
      }
}

std::string Textbook::display_product_info()
{
      std::string info = "ID: " + std::to_string(getId()) + "\n";
      info += "Title: " + getTitle() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      info += "Subject: " + getSubject() + "\n";
      return info;
}

Textbook::~Textbook(){}
