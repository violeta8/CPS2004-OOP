#include "shipment.hpp"
#include <list>

class ShipmentRepository
{
      public:
            static int nextIdShipment();
            static void addShipment(Shipment shipment);
            static void removeShipment(Shipment shipment);
            static void updateShipment(int id, std::string what, std::string change);
            static Shipment getShipmentbyId(int id);
            static std::string getAllShipments();
            ~ShipmentRepository();

      private:
            static std::list<Shipment> repository;
            static int nextId_;
};