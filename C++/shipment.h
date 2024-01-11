#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <iostream>
#include <string>
#include <vector>

#include "fecha.hpp"
#include "packaging.h"
#include "transport.h"
#include "customer.h"
class Shipment
{
      public:
            Shipment(int id, Fecha dispatch_date, Fecha arrival_date, std::vector<Packaging*> packagings, Transport* transport,Customer* customer);

            void setDispatchDate(Fecha dispatch_date);
            void setArrivalDate(Fecha arrival_date);
            void setPackagings(std::vector<Packaging*> packagings);
            void setTransport(Transport* transport);
            void setCustomer(Customer* customer);

            Fecha getDispatchDate() const;
            Fecha getArrivalDate() const;
            double getNearestWarehouse() const;
            std::vector<Packaging*> getPackagings() const;
            Transport* getTransport() const;
            Customer* getCustomer() const;

            double calculateTotalCost() const;
            
      private:
            int id;     
            Fecha dispatch_date_;
            Fecha arrival_date_;
            std::vector<Packaging*> packagings_;
            Transport* transport_;
            Customer* customer_;
};

#endif // SHIPMENT_H