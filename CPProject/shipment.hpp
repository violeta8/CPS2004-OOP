#include <iostream>
#include <list>

#include "customer.hpp"
#include "packaging.hpp"
#include "transport.hpp"
#include "fecha.hpp"

class Shipment{
      public:
            Shipment(int id, Customer customer, Transport& transport);
            //both dates cannot be wrong as they are created by the system and the current date

            void updateShipment(std::string change, std::string value);

            int getIdShipment() const;
            Customer getCustomer() const;
            Transport& getTransport() const;
            Fecha getPurchaseDate() const;
            Fecha getDeliveryDate() const;
            std::list<Packaging> getPackaging() const;
            Fecha setDeliveryDate();


            void setCustomer(Customer customer);
            void setTransport(Transport& transport);

            void addPackaging(Packaging packaging);
      
            void display_shipment_info() const;
            ~Shipment();
      
      private:
            int idShipment_;
            Customer customer_;
            Transport& transport_;//todo check this
            std::list<Packaging> packaging_;
            Fecha purchaseDate_;
            Fecha deliveryDate_;
};