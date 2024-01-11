#include "transport.h"

Transport::Transport(int id, double speed, double costPerKm): id_(id), speed_(speed), costPerKm_(costPerKm){}

void Transport::setId(int id){ id_ = id; }
void Transport::setSpeed(double speed){ speed_ = speed; }
void Transport::setCostPerKm(double costPerKm){ costPerKm_ = costPerKm; }

int Transport::getId() const{ return id_; }
double Transport::getSpeed() const{ return speed_; }
double Transport::getCostPerKm() const{ return costPerKm_; }
