#ifndef TRANSPORT_HPP_
#define TRANSPORT_HPP_

#include <iostream> 
#include <string>

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
            virtual int route() const = 0;
            virtual ~Transport();
            
      private:
            int id_;
            double speed_;
            double costPerKm_;
};

class Airplane : public Transport
{
      public:
            Airplane(int id, double speed, double costPerKm, std::string model);
            void setModel(std::string model_);
            std::string getModel() const;

            ~Airplane();

      private:
            std::string model_;
};

class Truck : public Transport
{
      public:
            Truck(int id, double speed, double costPerKm, std::string plate);
            void setPlate(std::string plate_);
            std::string getPlate() const;

            ~Truck();
      private:
            std::string plate_;
}     ;

class Ship : public Transport
{
      public:
            Ship(int id, double speed, double costPerKm, std::string name);
            void setName(std::string name_);
            std::string getName() const;

            ~Ship();
      private:
            std::string name_;
}  ;

#endif // TRANSPORT_HPP_