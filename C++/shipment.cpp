#include "shipment.h"

Shipment::Shipment(int id, Fecha dispatch_date, Fecha arrival_date, std::vector<Packaging*> packagings, Transport* transport, Customer* customer)
: dispatch_date_(dispatch_date), arrival_date_(arrival_date), packagings_(packagings), transport_(transport), customer_(customer){}

void Shipment::setDispatchDate(Fecha dispatch_date){ dispatch_date_ = dispatch_date; }
void Shipment::setArrivalDate(Fecha arrival_date){ arrival_date_ = arrival_date; }
void Shipment::setPackagings(std::vector<Packaging*> packagings){ packagings_ = packagings; }
void Shipment::setTransport(Transport* transport){ transport_ = transport; }
void Shipment::setCustomer(Customer* customer){ customer_ = customer; }

Fecha Shipment::getDispatchDate() const{ return dispatch_date_; }
Fecha Shipment::getArrivalDate() const{ return arrival_date_; }
std::vector<Packaging*> Shipment::getPackagings() const{ return packagings_; }
Transport* Shipment::getTransport() const{ return transport_; }
Customer* Shipment::getCustomer() const{ return customer_; }

double Shipment::calculateTotalCost() const
{
      double total_cost = 0;
      for(auto i=customer_->getProducts().begin();i!=customer_->getProducts().end();i++)
      {
            double costPerProduct;
            costPerProduct+= i->first->getPrice() * i->second;
            for(auto j=packagings_.begin();j!=packagings_.end();j++)
            {
                  // if(i->first->getId() == (*j)->getProduct().getId())
                  // {
                  //       costPerProduct += (*j)->getCost();
                  // }
            }
            double discount= costPerProduct* i->first->calculate_discount(i->second);
            total_cost += costPerProduct - discount;
      }
      total_cost += transport_->getCostPerKm() * customer_->getNearestWarehouse();;
      return total_cost;
}