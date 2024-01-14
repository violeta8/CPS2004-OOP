#include "shipment.hpp"

Shipment::Shipment(int id,Customer customer, Transport& transport):
      idShipment_(id), customer_(customer), transport_(transport), purchaseDate_(Fecha()), deliveryDate_(Fecha()){}

void Shipment::updateShipment(std::string change, std::string value)
{   
      if(change == "customer")
      {
            customer_.setId(std::stoi(value));
      }
      else if(change == "transport")
      {
            transport_.setId(std::stoi(value));
      }
      else if(change == "deliveryDate")
      {
            Fecha aux(value);
            deliveryDate_ = aux;
      }
      else
      {
            std::cout << "Wrong input" << std::endl;
      }
}

int Shipment::getIdShipment() const
{
      return idShipment_;
}

Customer Shipment::getCustomer() const
{
      return customer_;
}

Transport& Shipment::getTransport() const
{
      return transport_;
}

Fecha Shipment::getPurchaseDate() const
{
      return purchaseDate_;
}     

Fecha Shipment::getDeliveryDate() const
{
      return deliveryDate_;
}

std::list<Packaging> Shipment::getPackaging() const
{
      return packaging_;
}

Fecha Shipment::setDeliveryDate()
{
      Fecha aux;
      deliveryDate_ = aux;
      return deliveryDate_;
}

void Shipment::setCustomer(Customer customer)
{
      customer_ = customer;
}

void Shipment::setTransport(Transport& transport)
{
      transport_ = transport;
}

void Shipment::addPackaging(Packaging packaging)
{
      packaging_.push_back(packaging);
}

void Shipment::display_shipment_info() const
{
      std::cout << "Shipment ID: " << idShipment_ << std::endl;
      std::cout << "Customer ID: " << customer_.getId() << std::endl;
      std::cout << "Transport ID: " << transport_.getId() << std::endl;
      std::cout << "Purchase date: " << purchaseDate_.cadena() << std::endl;
      std::cout << "Delivery date: " << deliveryDate_.cadena() << std::endl;
      std::cout << "Packaging: " << std::endl;
      for(auto i : packaging_)
      {
            i.display_packaging_info();
      }
}

Shipment::~Shipment()
{
      packaging_.clear();
}