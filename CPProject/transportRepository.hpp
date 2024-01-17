#include "transport.hpp"
#include <list>

class TransportRepository
{
      public:
            static int nextIdTransport();
            static void addTransport(Transport* transport);
            static void removeTransport(Transport* transport);
            static void updateTransport(int id, std::string what, std::string change);
            static Transport* getTransportbyId(int id);
            static std::string getAllTransports();
            ~TransportRepository();

      private:
            static std::list<Transport*> repository;
            static int nextId_;
};

