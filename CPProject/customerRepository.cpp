#include "customerRepository.hpp"

int CustomerRepository::nextId=0;

std::list<Customer> CustomerRepository::repository = std::list<Customer>();

int CustomerRepository::nextIdCustomer()
{
      return nextId++;
}

void CustomerRepository::addCustomer(const Customer customer)
{
      repository.push_back(customer);
}

void CustomerRepository::removeCustomer(const Customer customer)
{
      repository.remove(customer);
}

void CustomerRepository::updateCustomer(int id, std::string what, std::string change)
{
     for(std::list<Customer>::iterator it = repository.begin(); it != repository.end(); ++it)
     {
           if (it->getId() == id)
           {
                  if (what == "name")
                  {
                        it->setName(change);
                  }
                  else if (what == "address")
                  {
                        it->setAddress(change);
                  }
                  else if (what == "phone")
                  {
                        it->setPhone(change);
                  }
                  else if (what == "email")
                  {
                        it->setEmail(change);
                  }
           }
     }
}

Customer CustomerRepository::getCustomerbyId(int idCustomer) 
{
      for (std::list<Customer>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == idCustomer)
            {
                  return *it;
            }
      }
      return Customer(0, "", "", "", "", 0);
}

std::string CustomerRepository::getAllCustomers()
{
      std::string result = "";
      for (std::list<Customer>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += it->display_customer_info() + "\n";
      }
      return result;
}

CustomerRepository::~CustomerRepository(){}