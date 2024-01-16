#include <iostream>
#include "fecha.hpp"
#include "packaging.hpp"
#include "supplier.hpp"
#include "product.hpp"
#include "transport.hpp"
#include "shipment.hpp"
#include "stock.hpp"
#include "stockRepository.hpp"
#include "supplierRepository.hpp"
#include "productRepository.hpp"
#include "transportRepository.hpp"
#include "customerRepository.hpp"
#include "book.hpp"
#include "clothing.hpp"
#include "electronic.hpp"
#include "food.hpp"
#include "computergame.hpp"
#include "homeappliance.hpp"

using namespace std;

int main(){
    cout<< "Escribe nombre, direccion, telefono y email del proveedor: ";
    string name, address, phone, email;
    cin>> name>> address>> phone>> email;
    Customer s(name, address, phone, email);
    cout<<s.display_customer_info()<<endl;
}