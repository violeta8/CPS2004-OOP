#include "customer.hpp"
#include <list>
#include <iostream>     

static class customerRepository
{
      public:
            customerRepository();
            static void addCustomer(Customer customer);
            static void removeCustomer(Customer customer);
            static void updateCustomer(int id, std::string what, std::string change);
            static Customer getCustomerbyId(int idCustomer) ;
            friend std::ostream& operator<< (std::ostream& os, const customerRepository& customerRepository);
            ~customerRepository();
      
      private:
            static std::list<Customer> repository;
};

void customerRepository::addCustomer(Customer Customer)
{
      repository.push_back(Customer);
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

std::ostream& operator<< (std::ostream& os, const customerRepository& customerRepository)
{
      //print the repository
      for (std::list<Customer>::const_iterator it = customerRepository.repository.begin(); it != customerRepository.repository.end(); ++it)
      {
            os << *it << std::endl;
      }
      return os;
}

customerRepository::~customerRepository(){}