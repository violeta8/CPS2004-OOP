#include "customer.hpp"

Customer::Customer(int id, std::string name, std::string address, std::string phone, std::string email, double warehouseDistance)
{
      idCustomer_= id;
      name_ = name;
      address_ = address;
      phone_ = phone;
      email_ = email;
      warehouseDistance_ = warehouseDistance;
}

void Customer::setId(int id)
{
      idCustomer_ = id;
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

std::string Customer::display_customer_info()const
{
      std::string info = "Customer [ID:" + std::to_string(getId()) + ", Name: " + getName() + ", Address: " +
                         getAddress() + ", Phone: " + getPhone() + ", Email: " +
                         getEmail() + ", Warehouse distance: " + std::to_string(getWarehouseDistance()) + "]";
      return info;
}

bool operator==(const Customer& customer, const Customer& customer2)
{
      return (customer.getId() == customer2.getId());
}

Customer::~Customer(){}