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

            virtual void updateTransport(std::string what, std::string change);
            virtual std::string display_transport_info()const;

            int getId() const;
            double getSpeed() const;
            double getCostPerKm() const;
            virtual int route() const = 0;

            friend bool operator==(const Transport& transport, const Transport& transport2);

            virtual ~Transport();
            
      private:
            int id_;
            double speed_;
            double costPerKm_;
};

class Plane : public Transport
{
      public:
            Plane(int id, double speed, double costPerKm);
            void setModel(std::string model_);
            std::string getModel() const;

            void updateTransport(std::string what, std::string change)override;
            std::string display_transport_info()const override;

            int route() const;

            ~Plane();

      private:
            std::string model_;
};

class Truck : public Transport
{
      public:
            Truck(int id, double speed, double costPerKm);
            void setPlate(std::string plate_);
            std::string getPlate() const;

            void updateTransport(std::string what, std::string change)override;
            std::string display_transport_info()const override;

            int route() const;

            ~Truck();
      private:
            std::string plate_;
}     ;

class Ship : public Transport
{
      public:
            Ship(int id, double speed, double costPerKm);
            void setName(std::string name_);
            std::string getName() const;

            void updateTransport(std::string what, std::string change)override;
            std::string display_transport_info()const override;

            int route() const;

            ~Ship();
      private:
            std::string name_;
}  ;

#endif // TRANSPORT_HPP_