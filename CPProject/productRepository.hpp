#include "product.hpp"
#include <list>

class ProductRepository
{
public:
      ProductRepository();
      int nextIdProduct();
      void addProduct(Product* product);
      void removeProduct(Product* product);
      void updateProduct(int id, std::string what, std::string change);
      Product* getProductbyId(int id);
      std::string getAllProducts()const;
      std::string getAllProductsbySupplier(int idSupplier)const;
      ~ProductRepository();

private:
      std::list<Product*> repository;
      int id_;
};

ProductRepository::ProductRepository(){
      repository = std::list<Product*>();
      id_ = 0;
}

int ProductRepository::nextIdProduct()
{
      return id_++;
}

void ProductRepository::addProduct(Product* product)
{
      repository.push_back(product);
}

void ProductRepository::removeProduct(Product* product)
{
      repository.remove(product);
}

void ProductRepository::updateProduct(int id, std::string what, std::string change) //todo check this
{
      for(std::list<Product*>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if ((*it)->getId() == id)
            {
                  (*it)->updateProduct(what, change);
            }
      }
}

Product* ProductRepository::getProductbyId(int id)
{
      for(std::list<Product*>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if ((*it)->getId() == id)
            {
                  return (*it);
            }
      }
      return *repository.end();
}

std::string ProductRepository::getAllProducts()const
{
      std::string result = "";
      for(std::list<Product*>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += (*it)->display_product_info();
      }
      return result;
}

std::string ProductRepository::getAllProductsbySupplier(int idSupplier)const
{
      std::string result = "";
      for(std::list<Product*>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if ((*it)->getSupplier().getId() == idSupplier)
            {
                  result += (*it)->display_product_info();
            }
      }
      return result;
}

ProductRepository::~ProductRepository()
{
      repository.clear();
}