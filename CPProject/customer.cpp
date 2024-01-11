#include "customer.hpp"

Customer::Customer(std::string name, std::string address, std::string phone, std::string email)
{
      idCustomer_=0;//todo
      name_ = name;
      address_ = address;
      phone_ = phone;
      email_ = email;
}

int Customer::getId() const
{
      return idCustomer_;
}

void Customer::setName(std::string name)
{
      name_ = name;
}

void Customer::setAddress(std::string address)
{
      address_ = address;
}

void Customer::setPhone(std::string phone)
{
      phone_ = phone;
}

void Customer::setEmail(std::string email)
{
      email_ = email;
}

void Customer::setWarehouseDistance(double warehouseDistance)
{
      warehouseDistance_ = warehouseDistance;
}

std::string Customer::getName() const
{
      return name_;
}

std::string Customer::getAddress() const
{
      return address_;
}

std::string Customer::getPhone() const
{
      return phone_;
}

std::string Customer::getEmail() const
{
      return email_;
}

double Customer::getWarehouseDistance() const
{
      return warehouseDistance_;
}

std::ostream& operator<< (std::ostream& os, const Customer& Customer)
{
      os << "ID: " << Customer.getId() << "\n";
      os << "Name: " << Customer.getName() << "\n";
      os << "Address: " << Customer.getAddress() << "\n";
      os << "Phone: " << Customer.getPhone() << "\n";
      os << "Email: " << Customer.getEmail() << "\n";
      os << "Warehouse distance: " << Customer.getWarehouseDistance() << "\n";
      return os;
}