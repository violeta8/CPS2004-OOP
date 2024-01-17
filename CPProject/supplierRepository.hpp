#include "supplier.hpp"
#include <list>
#include <iostream>

class SupplierRepository
{
      public:
            static int nextIdSupplier();
            static void addSupplier(const Supplier Supplier);
            static void removeSupplier(const Supplier Supplier);
            static void updateSupplier(int id, std::string what, std::string change);
            static Supplier getSupplierbyId(int idSupplier);
            static std::string getAllSuppliers();
            ~SupplierRepository();
      
      private:
            static std::list<Supplier> repository;
            static int nextId;
};

