#include "customerRepository.hpp"

int customerRepository::nextId=0;

std::list<Customer> customerRepository::repository = std::list<Customer>();

int customerRepository::nextIdCustomer()
{
      return nextId++;
}

void customerRepository::addCustomer(Customer Customer)
{
      repository.push_back(Customer);
      Customer.setId(nextIdCustomer());
}

void customerRepository::removeCustomer(Customer Customer)
{
      repository.remove(Customer);
}

void customerRepository::updateCustomer(int id, std::string what, std::string change)
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

Customer customerRepository::getCustomerbyId(int idCustomer) 
{
      for (std::list<Customer>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == idCustomer)
            {
                  return *it;
            }
      }
      return Customer("","","","");
}

std::string customerRepository::getAllCustomers()
{
      std::string result = "";
      for (std::list<Customer>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += it->display_customer_info() + "\n";
      }
      return result;
}

customerRepository::~customerRepository(){}