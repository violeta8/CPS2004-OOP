#include "transportRepository.hpp"

int TransportRepository::nextId_ = 0;

std::list<Transport*> TransportRepository::repository = std::list<Transport*>();

int TransportRepository::nextIdTransport()
{
      return nextId_++;
}

void TransportRepository::addTransport(Transport* transport)
{
      repository.push_back(transport);
}

void TransportRepository::removeTransport(Transport* transport)
{
      repository.remove(transport);
      delete transport;
}

void TransportRepository::updateTransport(int id, std::string what, std::string change)
{
      for(std::list<Transport*>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if ((*it)->getId() == id)
            {
                  (*it)->updateTransport(what, change);
            }
      }
}

Transport* TransportRepository::getTransportbyId(int id)
{
      for(std::list<Transport*>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if ((*it)->getId() == id)
            {
                  return *it;
            }
      }
      return *repository.end();
}

std::string TransportRepository::getAllTransports()
{
      std::string result = "";
      for(std::list<Transport*>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            result += (*it)->display_transport_info() + "\n";
      }
      return result;
}

TransportRepository::~TransportRepository(){}