#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#include <vector>

class Transport
{
      public:
            Transport(int id, double speed, double costPerKm);

            void setId(int id);
            void setSpeed(double speed);
            void setCostPerKm(double costPerKm);

            int getId() const;
            double getSpeed() const;
            double getCostPerKm() const;

      private:
            int id_;
            double speed_;
            double costPerKm_;
};

class Truck: public Transport{};
class Ship: public Transport{};
class Plane: public Transport{};

#endif // TRANSPORT_H
