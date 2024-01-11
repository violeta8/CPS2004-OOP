#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "shipment.h"
#include "product.h"


class Customer
{
public:
      Customer(std::string name, std::string email, std::string password, std::string credit_card, double nearestWarehouse, std::vector<Shipment*> shipment, std::map<Product*, int> products);//CONSTRUCTOR FOR THE ADMIN
      void setId(int id);
      void setName(std::string name);
      void setEmail(std::string email);
      void setPassword(std::string password);
      void setCreditCard(std::string credit_card);
      void setNearestWarehouse(double nearestWarehouse);
      void addShipment(Shipment* shipment);//TODO esto deberia de hacerlo solo cuando se termine de comprar 'x' productos(?)
      void cancelShipment(Shipment* shipment);
      void addProduct(Product* product, int quantity);

      int getId() const;
      std::string getName() const;
      std::string getEmail() const;
      std::string getPassword() const;
      std::string getCreditCard() const;
      double getNearestWarehouse() const;
      std::map<Product*, int> getProducts() const;
      int productsSize() const;
      int productQuantity(Product* product) const;

private:
      int id_=CustomerId++;
      std::string name_;
      std::string email_;
      std::string password_;
      std::string credit_card_;
      double nearestWarehouse_;
      std::vector<Shipment*> shipment_;
      std::map<Product*, int> products_;
      int CustomerId = -1;
};

#endif // CUSTOMER_H
