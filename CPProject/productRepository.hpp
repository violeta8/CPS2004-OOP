#include "product.hpp"
#include <list>

class ProductRepository
{
public:
      ProductRepository();
      static int nextIdProduct();
      static void addProduct(Product& product);
      static void removeProduct(Product& product);
      static void updateProduct(int id, std::string what, std::string change);
      static Product& getProductbyId(int id);
      friend std::ostream& operator<< (std::ostream& os, const ProductRepository& productRepository);
      ~ProductRepository();

private:
      static std::list<Product> repository;
      static int id_;
};

ProductRepository::ProductRepository(){
      repository = std::list<Product>();
      id_ = 0;
}

int ProductRepository::nextIdProduct()
{
      return id_++;
}

void ProductRepository::addProduct(Product& product)
{
      repository.push_back(product);
}

void ProductRepository::removeProduct(Product& product)
{
      repository.remove(product);
}

void ProductRepository::updateProduct(int id, std::string what, std::string change) //todo check this
{
      for(std::list<Product>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == id)
            {
                  it->updateProduct(what, change);
            }
      }
}

Product& ProductRepository::getProductbyId(int id)
{
      for(std::list<Product>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == id)
            {
                  return *it;
            }
      }
      return *repository.end();
}

std::ostream& operator<< (std::ostream& os, const ProductRepository& productRepository)
{
      for(std::list<Product>::const_iterator it = productRepository.repository.begin(); it != productRepository.repository.end(); ++it)
      {
            os << it->display_product_info() << std::endl;//todo fix this
      }
      return os;
}