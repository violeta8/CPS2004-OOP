#include "stock.h"

Stock::Stock(int capacity) : capacity_(capacity){}

void Stock::addProduct(){ capacity_++; }

void Stock::removeProduct(){ capacity_--; }

int Stock::getStock() const{ return capacity_; }