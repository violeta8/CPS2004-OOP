#include "customer.hpp"

#include <list>
#include <iostream>     

class customerRepository
{
      public:
            static int nextIdCustomer();
            static void addCustomer(Customer customer);
            static void removeCustomer(Customer customer);
            static void updateCustomer(int id, std::string what, std::string change);
            static Customer getCustomerbyId(int idCustomer) ;
            static std::string getAllCustomers();
            ~customerRepository();

      private:
            static std::list<Customer> repository;
            static int nextId;
};
