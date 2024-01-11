#include "transport.hpp"

Transport::Transport(int id, double speed, double costPerKm)
      : id_(id), speed_(speed), costPerKm_(costPerKm){}

void Transport::setId(int id) { id_ = id; }

void Transport::setSpeed(double speed) { speed_ = speed; }

void Transport::setCostPerKm(double costPerKm) { costPerKm_ = costPerKm; }

int Transport::getId() const { return id_; }

double Transport::getSpeed() const { return speed_; }

double Transport::getCostPerKm() const { return costPerKm_; }

Transport::~Transport(){}


Airplane::Airplane(int id, double speed, double costPerKm, std::string model)
      : Transport(id, speed, costPerKm), model_(model){}

void Airplane::setModel(std::string model) { model_ = model; }

std::string Airplane::getModel() const { return model_; }

Airplane::~Airplane(){}


Truck::Truck(int id, double speed, double costPerKm, std::string plate)
      : Transport(id, speed, costPerKm), plate_(plate){}

void Truck::setPlate(std::string plate) { plate_ = plate; }

std::string Truck::getPlate() const { return plate_; }

Truck::~Truck(){}


Ship::Ship(int id, double speed, double costPerKm, std::string name)
      : Transport(id, speed, costPerKm), name_(name){}

void Ship::setName(std::string name) { name_ = name; }

std::string Ship::getName() const { return name_; }

Ship::~Ship(){}