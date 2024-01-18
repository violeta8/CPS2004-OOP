#include "supplierRepository.hpp"

int SupplierRepository::nextId = 0;

std::list<Supplier> SupplierRepository::repository = std::list<Supplier>();

int SupplierRepository::nextIdSupplier()
{
      return nextId++;
}

void SupplierRepository::addSupplier(const Supplier Supplier)
{
      repository.push_back(Supplier);
}

void SupplierRepository::removeSupplier(const Supplier Supplier)
{
      repository.remove(Supplier);
}

void SupplierRepository::updateSupplier(int id, std::string what, std::string change)
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

Supplier SupplierRepository::getSupplierbyId(int idSupplier) 
{
      for (std::list<Supplier>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == idSupplier)
            {
                  return *it;
            }
      }
      return Supplier(-1,"","","","");
}

std::string SupplierRepository::getAllSuppliers()
{
      std::string info = "";
      for (std::list<Supplier>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            info += it->display_supplier_info() + "\n";
      }
      return info;
}
SupplierRepository::~SupplierRepository()
{
      
}
