#include "supplier.h"

Supplier::Supplier(int id, std::string name, std::string email, std::string password, std::string credit_card)
: id_(id), name_(name), email_(email), password_(password), credit_card_(credit_card), products_(std::vector<Product*>()){}

void Supplier::setId(int id){ id_ = id; }
void Supplier::setName(std::string name){ name_ = name; }
void Supplier::setEmail(std::string email){ email_ = email; }
void Supplier::setPassword(std::string password){ password_ = password; }
void Supplier::setCreditCard(std::string credit_card){ credit_card_ = credit_card; }

int Supplier::getId() const{ return id_; }
std::string Supplier::getName() const{ return name_; }
std::string Supplier::getEmail() const{ return email_; }
std::string Supplier::getPassword() const{ return password_; }
std::string Supplier::getCreditCard() const{ return credit_card_; }
std::vector<Product*> Supplier::getProducts() const{ return products_; }