#include <iostream>
#include <list>

#include "customer.hpp"
#include "product.hpp"
#include "packaging.hpp"
#include "transport.hpp"
#include "fecha.hpp"

class Shipment{
      public:
            Shipment(Customer customer, Product product, std::list<Packaging> packaging, int units);
            void setCustomer(Customer customer);
            void setProduct(Product product);
            void setPackaging(Packaging packaging);
            void setUnits(int units);
            Customer getCustomer() const;
            Product getProduct() const;
            Packaging getPackaging() const;
            int getUnits() const;
      
            void display_info() const;
            ~Shipment();
      
      private:
            int idShipment_;
            Customer customer_;
            Transport* transport_;//todo check this
            std::list<Packaging> packaging_;
            Fecha purchaseDate_;
            Fecha deliveryDate_;
};