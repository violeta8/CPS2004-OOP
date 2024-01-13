#include <iostream>
#include "fecha.hpp"
#include "packaging.hpp"
#include "supplier.hpp"
#include "product.hpp"
#include "transport.hpp"
// #include "shipment.hpp"
#include "stock.hpp"
#include "stockRepository.cpp"
#include "supplierRepository.cpp"
#include "productRepository.cpp"
#include "transportRepository.cpp"
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
    Supplier s(name, address, phone, email);
    cout<<s.display_supplier_info()<<endl;
}