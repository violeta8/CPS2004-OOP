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
#include "shipmentRepository.hpp"
#include "book.hpp"
#include "clothing.hpp"
#include "electronic.hpp"
#include "food.hpp"
#include "computergame.hpp"
#include "homeappliance.hpp"

using namespace std;

void index()
{
    cout << "Select what do you want to do:" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Supplier" << endl;
    cout << "3. Transport" << endl;
    cout << "4. Product" << endl;
    cout << "5. Stock" << endl;
    cout << "6. Shipment" << endl;
}

void CreateCustomer()
{
    string name, address, phone, email;
    double distance;
    cout << "You have selected to add a customer" << endl;
    cout << "Please enter the customer's name" << endl;
    cin >> name;
    cout << "Please enter the customer's address" << endl;
    cin >> address;
    cout << "Please enter the customer's phone" << endl;
    cin >> phone;
    cout << "Please enter the customer's email" << endl;
    cin >> email;
    cout << "Please enter the customer's warehouse distance" << endl;
    cin >> distance;
    Customer customer(CustomerRepository::nextIdCustomer(), name, address, phone, email, distance);
    CustomerRepository::addCustomer(customer);
}

void DeleteCustomer()
{
    cout << "You have selected to delete a customer" << endl;
    cout << "Please enter the customer's id" << endl;
    int id;
    cin >> id;
    Customer customer = CustomerRepository::getCustomerbyId(id);
    CustomerRepository::removeCustomer(customer);
}

void UpdateCustomer()
{
    cout << "You have selected to update a customer" << endl;
    cout << "Please enter the customer's id" << endl;
    int id;
    cin >> id;
    cout << "Please enter what do you want to update" << endl;
    string what,change;
    cin >> what;
    cout << "Please enter the new value" << endl;
    cin >> change;
    CustomerRepository::updateCustomer(id, what, change);
}

void ShowCustomer()
{
    cout << "You have selected to show a customer" << endl;
    cout << "Please enter the customer's id" << endl;
    int id;
    cin >> id;
    Customer customer = CustomerRepository::getCustomerbyId(id);
    cout << customer.display_customer_info() << endl;
}

void CustomerMenu()
{
    cout << "You are in the Customer's menu" << endl;
    cout << "1. Add customer" << endl;
    cout << "2. Delete customer" << endl;
    cout << "3. Modify customer" << endl;
    cout << "4. Show all customers" << endl;
    int option;
    cin >> option;
    switch(option)
    {
        case 1:
            CreateCustomer();
            break;
        case 2:
            DeleteCustomer();
            break;
        case 3:
            UpdateCustomer();
            break;
        case 4:
            cout << CustomerRepository::getAllCustomers() << endl;
            break;
        default:
            break;
    }
}

void CreateSupplier()
{
    string name, address, phone, email;
    cout << "You have selected to add a supplier" << endl;
    cout << "Please enter the supplier's name" << endl;
    cin >> name;
    cout << "Please enter the supplier's address" << endl;
    cin >> address;
    cout << "Please enter the supplier's phone" << endl;
    cin >> phone;
    cout << "Please enter the supplier's email" << endl;
    cin >> email;
    Supplier supplier(name, address, phone, email);
    SupplierRepository::addSupplier(supplier);
}

void DeleteSupplier()
{
    cout << "You have selected to delete a supplier" << endl;
    cout << "Please enter the supplier's id" << endl;
    int id;
    cin >> id;
    Supplier supplier = SupplierRepository::getSupplierbyId(id);
    SupplierRepository::removeSupplier(supplier);
}

void UpdateSupplier()
{
    cout << "You have selected to update a supplier" << endl;
    cout << "Please enter the supplier's id" << endl;
    int id;
    cin >> id;
    cout << "Please enter what do you want to update" << endl;
    string what,change;
    cin >> what;
    cout << "Please enter the new value" << endl;
    cin >> change;
    SupplierRepository::updateSupplier(id, what, change);
}

void SupplierMenu()
{
    cout << "You are in the Supplier's menu" << endl;
    cout << "1. Add supplier" << endl;
    cout << "2. Delete supplier" << endl;
    cout << "3. Modify supplier" << endl;
    cout << "4. Show all suppliers" << endl;
    int option;
    cin >> option;
    switch(option)
    {
        case 1:
            CreateSupplier();
            break;
        case 2:
            DeleteSupplier();
            break;
        case 3:
            UpdateSupplier();
            break;
        case 4:
            cout << SupplierRepository::getAllSuppliers() << endl;
            break;
        default:
            break;
    }
}

void CreateTransport()
{
    int cost; double speed;
    cout << "You have selected to add a transport" << endl;
    cout << "Please enter the transport's cost per KM" << endl;
    cin >> cost;
    cout << "Please enter the transport's speed" << endl;
    cin >> speed;
    int choice;
    cout << "Please enter the transport's type" << endl;
    cout << "1. Truck" << endl;
    cout << "2. Ship" << endl;
    cout << "3. Plane" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            Truck truck(TransportRepository::nextIdTransport(), speed, cost);
            TransportRepository::addTransport(&truck);
            break;
        case 2:
            Ship ship(TransportRepository::nextIdTransport(), speed, cost);
            TransportRepository::addTransport(&ship);
            break;
        case 3:
            Plane plane(TransportRepository::nextIdTransport(), speed, cost);
            TransportRepository::addTransport(&plane);
            break;
    }
}

void DeleteTransport()
{
    cout << "You have selected to delete a transport" << endl;
    cout << "Please enter the transport's id" << endl;
    int id;
    cin >> id;
    Transport* transport = TransportRepository::getTransportbyId(id);
    TransportRepository::removeTransport(transport);
}  

void updateTransport
{
    cout << "You have selected to update a transport" << endl;
    cout << "Please enter the transport's id" << endl;
    int id;
    cin >> id;
    cout << "Please enter what do you want to update" << endl;
    string what,change;
    cin >> what;
    cout << "Please enter the new value" << endl;
    cin >> change;
    TransportRepository::updateTransport(id, what, change);
}

void TransportMenu()
{
    cout << "You are in the Transport's menu" << endl;
    cout << "1. Add transport" << endl;
    cout << "2. Delete transport" << endl;
    cout << "3. Modify transport" << endl;
    cout << "4. Show all transports" << endl;
    int option;
    cin >> option;
    switch(option)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4: 
            break;
        default:
            break;
    }
}

int main(){
    
    
}