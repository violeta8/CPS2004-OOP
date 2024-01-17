#include "shipment.hpp"

Shipment::Shipment(int id,Customer customer, Transport* transport):
      idShipment_(id), customer_(customer), transport_(transport), purchaseDate_(Fecha()), deliveryDate_(Fecha()){}

void Shipment::updateShipment(std::string change, std::string value)
{   
      if(change == "transport")
      {
            Transport* t = TransportRepository::getTransportbyId(std::stoi(value));
            if(t != nullptr)
            {
                  transport_ = t;
            }
            else
            {
                  std::cout << "Wrong input" << std::endl;
            }
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

Transport* Shipment::getTransport() const
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

void Shipment::setTransport(Transport* transport)
{
      transport_ = transport;
}

void Shipment::addPackaging(Packaging packaging)
{
      packaging_.push_back(packaging);
}

std::string Shipment::display_shipment_info() const
{
      std::string info = "[Shipment: " + std::to_string(idShipment_) + ", " + customer_.display_customer_info() + 
      ", " + transport_->display_transport_info() + ", " + purchaseDate_.cadena() + ", " +
      deliveryDate_.cadena() + ", " + std::to_string(packaging_.size()) + "]\n";
}

Shipment::~Shipment()
{
      packaging_.clear();
}