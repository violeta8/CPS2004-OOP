#include "stock.hpp"
#include "product.hpp"

#include <list>


class StockRepository
{
    public:
            static void addStock(const Stock& stock);
            static void removeStock(Product* product);
            static void updateStock(Product* product, int units);
            static Stock getStock(int id);
            static int getStockQuantity(Product* product);
            static std::string getAllStock();
            ~StockRepository();

    private:
        static std::list<Stock> repository;
        static int nextId_;
};
