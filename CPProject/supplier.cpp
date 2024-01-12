#include "supplier.hpp"

Supplier::Supplier(std::string name, std::string address, std::string phone, std::string email)
      : id_(), name_(name), address_(address), phone_(phone), email_(email), products_(std::list<Product>()){}

int Supplier::getId() const{return id_;}

void Supplier::setName(std::string name) { name_ = name; }

void Supplier::setAddress(std::string address) { address_ = address; }

void Supplier::setPhone(std::string phone) { phone_ = phone; }

void Supplier::setEmail(std::string email) { email_ = email; }

std::string Supplier::getName() const { return name_; }

std::string Supplier::getAddress() const { return address_; }

std::string Supplier::getPhone() const { return phone_; }

std::string Supplier::getEmail() const { return email_; }

void Supplier::addProduct(Product& product) { products_.push_back(product); }

void Supplier::removeProduct(Product& product) { products_.remove(product); }

Supplier::~Supplier()
{
      products_.clear();
}

