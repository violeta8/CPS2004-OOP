#include "customer.hpp"
#include <list>
#include <iostream>     

class customerRepository
{
      public:
            customerRepository();
            int nextIdCustomer();
            void addCustomer(const Customer customer);
            void removeCustomer(const Customer customer);
            void updateCustomer(int id, std::string what, std::string change);
            Customer getCustomerbyId(int idCustomer) ;
            std::string getAllCustomers()const;
            ~customerRepository();

      private:
            std::list<Customer> repository;
            int nextId;
};

customerRepository::customerRepository(){
      repository = std::list<Customer>();
      nextId = 0;
}

int customerRepository::nextIdCustomer()
{
      return nextId++;
}

void customerRepository::addCustomer(const Customer Customer)
{
      repository.push_back(Customer);
}

void customerRepository::removeCustomer(const Customer Customer)
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

std::string customerRepository::getAllCustomers()const
{
      std::string result = "";
      for (std::list<Customer>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += it->display_customer_info() + "\n";
      }
      return result;
}

customerRepository::~customerRepository(){}