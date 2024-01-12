#include "transport.hpp"
#include <list>

class TransportRepository
{
      public:
            TransportRepository();
            static int nextIdTransport();
            static void addTransport(Transport& transport);
            static void removeTransport(Transport& transport);
            static void updateTransport(int id, std::string what, std::string change);
            static Transport& getTransportbyId(int id);
            friend std::ostream& operator<< (std::ostream& os, const TransportRepository& transportRepository);
            ~TransportRepository();

      private:
            static std::list<Transport> repository;
            static int id_;
}

TransportRepository::TransportRepository(){
      repository = std::list<Transport>();
      id_ = 0;
}

int TransportRepository::nextIdTransport()
{
      return id_++;
}

void TransportRepository::addTransport(Transport& transport)
{
      repository.push_back(transport);
}

void TransportRepository::removeTransport(Transport& transport)
{
      repository.remove(transport);
}

void TransportRepository::updateTransport(int id, std::string what, std::string change) //todo check this
{
      for(std::list<Transport>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == id)
            {
                  it->updateTransport(what, change);
            }
      }
}

Transport& TransportRepository::getTransportbyId(int id)
{
      for(std::list<Transport>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == id)
            {
                  return *it;
            }
      }
}

std::ostream& operator<< (std::ostream& os, const TransportRepository& transportRepository)
{
      for(std::list<Transport>::const_iterator it = transportRepository.repository.begin(); it != transportRepository.repository.end(); ++it)
      {
            os << *it << std::endl;
      }
      return os;
}