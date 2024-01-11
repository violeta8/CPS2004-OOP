#include "customer.h"

Customer::Customer(std::string name, std::string email, std::string password, std::string credit_card, double nearestWarehouse, std::vector<Shipment*> shipment, std::map<Product*, int> products)
: name_(name), email_(email), password_(password), credit_card_(credit_card), nearestWarehouse_(nearestWarehouse), shipment_(std::vector<Shipment*>()), products_(std::map<Product*,int>()){}

void Customer::setId(int id){ id_ = id; }
void Customer::setName(std::string name){ name_ = name; }
void Customer::setEmail(std::string email){ email_ = email; }
void Customer::setPassword(std::string password){ password_ = password; }
void Customer::setCreditCard(std::string credit_card){ credit_card_ = credit_card; }
void Customer::setNearestWarehouse(double nearestWarehouse){ nearestWarehouse_ = nearestWarehouse; }
void Customer::addShipment(Shipment* shipment){ shipment_.push_back(shipment); }
void Customer::addProduct(Product* product, int quantity)
{
      if(products_.find(product) == products_.end())
            products_.insert(std::pair<Product*, int>(product, quantity));
      else
            products_[product] += quantity;
}

int Customer::getId() const{ return id_; }
std::string Customer::getName() const{ return name_; }
std::string Customer::getEmail() const{ return email_; }
std::string Customer::getPassword() const{ return password_; }
std::string Customer::getCreditCard() const{ return credit_card_; }
double Customer::getNearestWarehouse() const{ return nearestWarehouse_; }
std::map<Product*, int> Customer::getProducts() const{ return products_; }
int Customer::productsSize() const{ return products_.size(); }
int Customer::productQuantity(Product* product) const{ return products_.at(product); }