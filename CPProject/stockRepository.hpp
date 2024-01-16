#include "stock.hpp"
#include "product.hpp"

#include <list>


class StockRepository
{
    public:
            StockRepository();
            void addStock(const Stock& stock);
            void removeStock( const int id);
            void updateStock(Product& product, int units);
            Stock& getStock(int id);
            int getStockQuantity(Product& product);
            std::string getAllStock()const;
            ~StockRepository();

    private:
        std::list<Stock> repository;
        int id_;
};

StockRepository::StockRepository()
{
      repository = std::list<Stock>();//todo not new(?)
      id_ = 0;
}

void StockRepository::addStock(const Stock& stock)
{
      repository.push_back(stock);
}

void StockRepository::removeStock(const int id)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct().getId() == id)
            {
                  repository.remove(*it);
            }
      }
}

void StockRepository::updateStock(Product& product, int units)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct().getId() == product.getId())
            {
                  it->updateStock(units);
            }
      }
}

Stock& StockRepository::getStock(int id)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct().getId() == id)
            {
                  return *it;
            }
      }
      return *repository.end();
}

int StockRepository::getStockQuantity(Product& product)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct().getId() == product.getId())
            {
                  return it->getUnits();
            }
      }
      return -1;
}

std::string StockRepository::getAllStock()const
{
      std::string info = "";
      for(std::list<Stock>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            info += it->display_stock_info();
      }
      return info;
}

StockRepository::~StockRepository()
{
      repository.clear();
      id_ = 0;
}