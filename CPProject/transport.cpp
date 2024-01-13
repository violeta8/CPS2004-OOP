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

int Transport::getId() const { return id_; }

double Transport::getSpeed() const { return speed_; }

double Transport::getCostPerKm() const { return costPerKm_; }

Transport::~Transport(){}



Airplane::Airplane(int id, double speed, double costPerKm, std::string model)
      : Transport(id, speed, costPerKm), model_(model){}

void Airplane::setModel(std::string model) { model_ = model; }

std::string Airplane::getModel() const { return model_; }

void Airplane::updateTransport(std::string what, std::string change)
{
      if (what == "model")
      {
            model_ = change;
      }
}

std::string Airplane::display_transport_info()const
{
      std::string info = "Airplane: " + std::to_string(getId()) + " \nThe speed is: " + std::to_string(getSpeed()) + " \nThe cost per km is: " + std::to_string(getCostPerKm()) + " \nAnd the model is: " + model_;
      return info;
}

Airplane::~Airplane(){}


Truck::Truck(int id, double speed, double costPerKm, std::string plate)
      : Transport(id, speed, costPerKm), plate_(plate){}

void Truck::setPlate(std::string plate) { plate_ = plate; }

std::string Truck::getPlate() const { return plate_; }

void Truck::updateTransport(std::string what, std::string change)
{
      if (what == "plate")
      {
            plate_ = change;
      }
}

std::string Truck::display_transport_info()const
{
      std::string info = "Truck: " + std::to_string(getId()) + " \nThe speed is: " + std::to_string(getSpeed()) + " \nThe cost per km is: " + std::to_string(getCostPerKm()) + " \nAnd the plate is: " + plate_;
      return info;
}

Truck::~Truck(){}


Ship::Ship(int id, double speed, double costPerKm, std::string name)
      : Transport(id, speed, costPerKm), name_(name){}

void Ship::setName(std::string name) { name_ = name; }

std::string Ship::getName() const { return name_; }

void Ship::updateTransport(std::string what, std::string change)
{
      if (what == "name")
      {
            name_ = change;
      }
}

std::string Ship::display_transport_info()const
{
      std::string info = "Ship: " + std::to_string(getId()) + " \nThe speed is: " + std::to_string(getSpeed()) + " \nThe cost per km is: " + std::to_string(getCostPerKm()) + " \nAnd the name is: " + name_;
      return info;
}

Ship::~Ship(){}