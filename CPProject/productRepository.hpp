#include "product.hpp"
#include <list>

class ProductRepository
{
public:
      static int nextIdProduct();
      static void addProduct(Product* product);
      static void removeProduct(Product* product);
      static void updateProduct(int id, std::string what, std::string change);
      static Product* getProductbyId(int id);
      static std::string getAllProducts();
      static std::string getAllProductsbySupplier(int idSupplier);
      ~ProductRepository();

private:
      static std::list<Product*> repository;
      static int nextId_;
};