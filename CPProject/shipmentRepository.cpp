#include "shipmentRepository.hpp"

int ShipmentRepository::nextId_ = 0;

std::list<Shipment> ShipmentRepository::repository = std::list<Shipment>();

int ShipmentRepository::nextIdShipment()
{
      return nextId_++;
}

void ShipmentRepository::addShipment(Shipment shipment)
{
      repository.push_back(shipment);
}

void ShipmentRepository::removeShipment(Shipment shipment)
{
      repository.remove(shipment);
}

void ShipmentRepository::updateShipment(int id, std::string what, std::string change)
{
      for(std::list<Shipment>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getIdShipment() == id)
            {
                  it->updateShipment(what, change);
            }
      }
}

Shipment ShipmentRepository::getShipmentbyId(int id)
{
      for(std::list<Shipment>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getIdShipment() == id)
            {
                  return *it;
            }
      }
      return *repository.end();
}

std::string ShipmentRepository::getAllShipments()
{
      std::string result = "";
      for(std::list<Shipment>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += it->display_shipment_info() + "\n";
      }
      return result;
}