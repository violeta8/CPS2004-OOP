#include "book.hpp"

Book::Book(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string author, std::string title, std::string genre, int pages) 
      : Product(id, price, monthPurchase, supplier, packaging, stock), title_(title), author_(author), genre_(genre), pages_(pages){}

void Book::setAuthor(std::string author) { author_ = author; }

void Book::setTitle(std::string title) { title_ = title; }

void Book::setGenre(std::string genre) { genre_ = genre; }

void Book::setPages(int pages) { pages_ = pages; }

std::string Book::getTitle() const { return title_; }

std::string Book::getAuthor() const { return author_; }

std::string Book::getGenre() const { return genre_; }

int Book::getPages() const { return pages_; }

Book::~Book(){}


Novel::Novel(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string author, std::string title, std::string genre, int pages, Fecha publicationDate) 
      : Book(id, price, monthPurchase, supplier, packaging, stock, author, title, genre, pages), publicationDate_(publicationDate){}

Fecha Novel::getPublicationDate() const { return publicationDate_; }

std::string Novel::display_product_info()
{
      std::string info = "ID: " + std::to_string(getId()) + "\n";
      info += "Title: " + getTitle() + "\n";
      info += "Author: " + getAuthor() + "\n";
      info += "Genre: " + getGenre() + "\n";
      info += "Pages: " + std::to_string(getPages()) + "\n";
      info += "Publication date: " (getPublicationDate()) + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      info += "Packaging: " + getPackaging().to_string() + "\n";//todo mirar si esto ta bien
      info += "Stock: " +  + "\n";
      info += "Supplier: " + getSupplier().to_string() + "\n";
      return info;
}

Novel::~Novel(){}



Textbook::Textbook(int id, double price, int monthPurchas, Supplier supplier, Packaging packaging, Stock stock, std::string author, std::string title, std::string genre, int pages, Fecha publicationDate, std::string subject, std::string course)
      : Novel(id, price, monthPurchase, supplier, packaging, stock, author, title, genre, pages), subject_(subject){}

void Textbook::setSubject(std::string subject) { subject_ = subject; }

std::string Textbook::getSubject() const { return subject_; }

std::string Textbook::display_product_info()
{
      std::string info = "ID: " + std::to_string(getId()) + "\n";
      info += "Title: " + getTitle() + "\n";
      info += "Author: " + getAuthor() + "\n";
      info += "Genre: " + getGenre() + "\n";
      info += "Pages: " + std::to_string(getPages()) + "\n";
      info += "Publication date: " + std::to_string(getPublicationDate()) + "\n";//todo mirar si esto ta bien
      info += "Price: " + std::to_string(getPrice()) + "\n";
      info += "Packaging: " + getPackaging().to_string() + "\n";
      info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
      info += "Supplier: " + getSupplier().to_string() + "\n";
      info += "Subject: " + getSubject() + "\n";
      return info;
}

Textbook::~Textbook(){}
