#include "stockRepository.hpp"

int StockRepository::nextId_ = 0;

std::list<Stock> StockRepository::repository = std::list<Stock>();

void StockRepository::addStock(const Stock& stock)
{
      repository.push_back(stock);
}

void StockRepository::removeStock(Product* product)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct()->getId() == product->getId())
            {
                  repository.erase(it);
            }
      }
}

void StockRepository::updateStock(Product* product, int units)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct()->getId() == product->getId())
            {
                  it->updateStock(units);
            }
      }
}

Stock StockRepository::getStock(int id)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct()->getId() == id)
            {
                  return *it;
            }
      }
      return *repository.end();
}

int StockRepository::getStockQuantity(Product* product)
{
      for(std::list<Stock>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getProduct()->getId() == product->getId())
            {
                  return it->getUnits();
            }
      }
      return -1;
}

std::string StockRepository::getAllStock()
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
      nextId_ = -1;
}