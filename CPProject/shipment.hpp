#include <iostream>
#include <list>

#include "customer.hpp"
#include "packaging.hpp"
#include "transport.hpp"
#include "fecha.hpp"
#include "transportRepository.hpp"

class Shipment{
      public:
            Shipment(int id, Customer customer, std::list<Packaging> packaging, Transport* transport, Fecha fecha);
            //both dates cannot be wrong as they are created by the system and the current date

            void updateShipment(std::string change, std::string value);

            int getIdShipment() const;
            Customer getCustomer() const;
            Transport* getTransport() const;
            Fecha getPurchaseDate() const;
            Fecha getDeliveryDate() const;
            std::list<Packaging> getPackaging() const;
            Fecha setDeliveryDate();
            double getTotalCost() const;

            void setCustomer(Customer customer);
            void setTransport(Transport* transport);

            void addPackaging(Packaging packaging);
      
            std::string display_shipment_info() const;

            friend bool operator==(const Shipment& s1, const Shipment& s2);
            ~Shipment();
      
      private:
            int idShipment_;
            Customer customer_;
            Transport* transport_;
            std::list<Packaging> packaging_;
            Fecha purchaseDate_;
            Fecha deliveryDate_;
};