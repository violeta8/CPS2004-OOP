#include "supplier.hpp"

Supplier::Supplier(std::string name, std::string address, std::string phone, std::string email)
      : id_(), name_(name), address_(address), phone_(phone), email_(email){}

int Supplier::getId() const{return id_;}

void Supplier::setName(std::string name) { name_ = name; }

void Supplier::setAddress(std::string address) { address_ = address; }

void Supplier::setPhone(std::string phone) { phone_ = phone; }

void Supplier::setEmail(std::string email) { email_ = email; }

std::string Supplier::getName() const { return name_; }

std::string Supplier::getAddress() const { return address_; }

std::string Supplier::getPhone() const { return phone_; }

std::string Supplier::getEmail() const { return email_; }

std::string Supplier::display_supplier_info()const
{
      std::string info = "";
      info += "Supplier id: " + std::to_string(id_) + "\n";
      info += "Supplier name: " + name_ + "\n";
      info += "Supplier address: " + address_ + "\n";
      info += "Supplier phone: " + phone_ + "\n";
      info += "Supplier email: " + email_ + "\n";
      return info;
}

Supplier::~Supplier(){}

