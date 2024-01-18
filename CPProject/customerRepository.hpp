#include "customer.hpp"

#include <list>

class CustomerRepository
{
      public:
            static int nextIdCustomer();
            static void addCustomer(const Customer customer);
            static void removeCustomer(const Customer customer);
            static void updateCustomer(int id, std::string what, std::string change);
            static Customer getCustomerbyId(int idCustomer);
            static std::string getAllCustomers();
            ~CustomerRepository();

      private:
            static std::list<Customer> repository;
            static int nextId;
};
