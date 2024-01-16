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
      std::string info = std::to_string(getId()) + " \nThe speed is: " + std::to_string(getSpeed()) + " \nThe cost per km is: " + std::to_string(getCostPerKm());
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



Plane::Plane(int id, double speed, double costPerKm, std::string model)
      : Transport(id, speed, costPerKm), model_(model){}

void Plane::setModel(std::string model) { model_ = model; }

std::string Plane::getModel() const { return model_; }

void Plane::updateTransport(std::string what, std::string change)
{
      Transport::updateTransport(what, change);
}

std::string Plane::display_transport_info()const
{
      std::string info = "[Plane: " + Transport::display_transport_info() + " ]";
      return info;
}

int Plane::route() const
{
      return 256;
}



Plane::~Plane(){}


Truck::Truck(int id, double speed, double costPerKm, std::string plate)
      : Transport(id, speed, costPerKm), plate_(plate){}

void Truck::setPlate(std::string plate) { plate_ = plate; }

std::string Truck::getPlate() const { return plate_; }

void Truck::updateTransport(std::string what, std::string change)
{
      Transport::updateTransport(what, change);
}

std::string Truck::display_transport_info()const
{
      std::string info = "[Truck: " + Transport::display_transport_info() + " ]";
      return info;
}

int Truck::route() const
{
      return 64;
}

Truck::~Truck(){}


Ship::Ship(int id, double speed, double costPerKm, std::string name)
      : Transport(id, speed, costPerKm), name_(name){}

void Ship::setName(std::string name) { name_ = name; }

std::string Ship::getName() const { return name_; }

void Ship::updateTransport(std::string what, std::string change)
{
      Transport::updateTransport(what, change);
}

std::string Ship::display_transport_info()const
{
      std::string info = "[Ship: " + Transport::display_transport_info() + " ]";
      return info;
}

int Ship::route() const
{
      return 128;
}

Ship::~Ship(){}