#include "productRepository.hpp"

int ProductRepository::nextId_ = 0;

std::list<Product*> ProductRepository::repository = std::list<Product*>();

int ProductRepository::nextIdProduct()
{
      return nextId_++;
}

void ProductRepository::addProduct(Product* product)
{
      repository.push_back(product);
      product->setId(nextIdProduct());
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

void ProductRepository::updateProduct(Product* product)
{
      for(std::list<Product*>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if ((*it) == product)
            {
                  (*it) = product;
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

std::string ProductRepository::getAllProducts()
{
      std::string result = "";
      for(std::list<Product*>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += (*it)->display_product_info();
      }
      return result;
}

std::string ProductRepository::getAllProductsbySupplier(int idSupplier)
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