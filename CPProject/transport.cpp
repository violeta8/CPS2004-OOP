#include "transport.hpp"

Transport::Transport(int id, double speed, double costPerKm)
      : id_(id), speed_(speed), costPerKm_(costPerKm){}

void Transport::setId(int id) { id_ = id; }

void Transport::setSpeed(double speed) { speed_ = speed; }

void Transport::setCostPerKm(double costPerKm) { costPerKm_ = costPerKm; }

void Transport::updateTransport(std::string what, std::string change)
{
      if (what == "speed")
      {
            speed_ = std::stod(change);
      }
      else if (what == "cost per km")
      {
            costPerKm_ = std::stod(change);
      }
}

std::string Transport::display_transport_info()const
{
      std::string info = "";
      info += "Transport: [ID: " + std::to_string(getId()) + ", ";
      info += " Speed: " + std::to_string(getSpeed()) + ", " ;
      info += "Cost per km: " + std::to_string(getCostPerKm())+ "]";
      return info;
}

int Transport::getId() const 
{ 
      return id_; 
}

double Transport::getSpeed() const { return speed_; }

double Transport::getCostPerKm() const { return costPerKm_; }

bool operator==(const Transport& transport, const Transport& transport2)
{
      return transport.getId() == transport2.getId();
}

Transport::~Transport(){}



Plane::Plane(int id, double speed, double costPerKm)
      : Transport(id, speed, costPerKm){}

void Plane::updateTransport(std::string what, std::string change)
{
      Transport::updateTransport(what, change);
}

std::string Plane::display_transport_info()const
{
      std::string res = "";
      res += "[Plane: " +  Transport::display_transport_info() + " ]";
      return res;
}

int Plane::route() const
{
      return 256;
}

Plane::~Plane(){}



Truck::Truck(int id, double speed, double costPerKm)
      : Transport(id, speed, costPerKm){}

void Truck::updateTransport(std::string what, std::string change)
{
      Transport::updateTransport(what, change);
}

std::string Truck::display_transport_info()const
{
      std::string res = "";
      res += "[Truck: " +  Transport::display_transport_info() + " ]";
      return res;
}

int Truck::route() const
{
      return 64;
}

Truck::~Truck(){}



Ship::Ship(int id, double speed, double costPerKm)
      : Transport(id, speed, costPerKm){}

void Ship::updateTransport(std::string what, std::string change)
{
      Transport::updateTransport(what, change);
}

std::string Ship::display_transport_info()const
{
      std::string res = "";
      res += "[Ship: " +  Transport::display_transport_info() + " ]";
      return res;
}

int Ship::route() const
{
      return 128;
}

Ship::~Ship(){}