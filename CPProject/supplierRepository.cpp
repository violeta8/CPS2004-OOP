#include "supplier.hpp"
#include <list>
#include <iostream>

class supplierRepository
{
      public:
            supplierRepository();
            int nextIdSupplier();
            void addSupplier(const Supplier Supplier);
            void removeSupplier(const Supplier Supplier);
            void updateSupplier(int id, std::string what, std::string change);
            void updateSupplier(int id, Product& p);
            Supplier getSupplierbyId(int idSupplier) ;
            std::string getAllSuppliers()const;
            ~supplierRepository();
      
      private:
            std::list<Supplier> repository;
            int nextId;
};

supplierRepository::supplierRepository(){
      repository = std::list<Supplier>();
      nextId = 0;
}

int supplierRepository::nextIdSupplier()
{
      return nextId++;
}

void supplierRepository::addSupplier(const Supplier Supplier)
{
      repository.push_back(Supplier);
}

void supplierRepository::removeSupplier(const Supplier Supplier)
{
      repository.remove(Supplier);
}

void supplierRepository::updateSupplier(int id, std::string what, std::string change)
{
     for(std::list<Supplier>::iterator it = repository.begin(); it != repository.end(); ++it)
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

void supplierRepository::updateSupplier(int id, Product& p)
{
      for(std::list<Supplier>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
             if (it->getId() == id)
             {
                     it->addProduct(p);
             }
      }
}

Supplier supplierRepository::getSupplierbyId(int idSupplier) 
{
      for (std::list<Supplier>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == idSupplier)
            {
                  return *it;
            }
      }
      return Supplier("","","","");
}

std::string supplierRepository::getAllSuppliers()const
{
      std::string info = "";
      for (std::list<Supplier>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            info += it->display_supplier_info();
      }
      return info;
}
supplierRepository::~supplierRepository()
{
      
}
