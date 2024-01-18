#include <iostream>
// #include "fecha.hpp"
// #include "packaging.hpp"
// #include "supplier.hpp"
// #include "product.hpp"
// #include "transport.hpp"
// #include "shipment.hpp"
// #include "stock.hpp"
#include "StockRepository.hpp"
#include "SupplierRepository.hpp"
#include "ProductRepository.hpp"
// #include "TransportRepository.hpp"
#include "CustomerRepository.hpp"
#include "ShipmentRepository.hpp"
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
    cout << "5. Shipment" << endl;
    cout << "6. Stock" << endl;
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
    string decision;
    do
    {
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
        cout << "Do you want to do anything more with Customers? yes/no" << endl;
        cin >> decision;
    }while (decision=="yes");
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
    Supplier supplier(SupplierRepository::nextIdSupplier(), name, address, phone, email);
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
    string decision;
    do
    {
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
        cout << "Do you want to do anything more with Suppliers? yes/no" << endl;
        cin >> decision;
    }while(decision=="yes");
}

void CreateTransport()
{
    double cost, speed;
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
    if(choice==1)//todo get this fixed and maybe on another function
    {
    
        Truck truck(TransportRepository::nextIdTransport(), speed, cost);
        TransportRepository::addTransport(&truck);
    }
    else if(choice==2)
    {
        Ship ship(TransportRepository::nextIdTransport(), speed, cost);
        TransportRepository::addTransport(&ship);
    }else if(choice==3)
    {
        Plane plane(TransportRepository::nextIdTransport(), speed, cost);
        TransportRepository::addTransport(&plane);
    }
    else{}
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

void UpdateTransport()
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
    string decision;
    do
    {
        cout << "1. Add transport" << endl;
        cout << "2. Delete transport" << endl;
        cout << "3. Modify transport" << endl;
        cout << "4. Show all transports" << endl;
        int option;
        cin >> option;
        switch(option)
        {
            case 1:
                CreateTransport();
                break;
            case 2:
                DeleteTransport();
                break;
            case 3:
                UpdateTransport();
                break;
            case 4: 
                cout << TransportRepository::getAllTransports() << endl;
                break;
            default:
                break;
        }
        string decision;
        cout << "Do you want to anything more with Transports? yes/no" << endl;
        cin >> decision;
    }while(decision=="yes");
}

void CreateProduct()//todo maybe change this bc it'll be the same problem as transport
{
    int idSupplier, volume, units; double price;
    cout << "You have selected to add a product" << endl;
    cout << "Please enter the product Supplier's ID" << endl;
    cin >> idSupplier;
    cout << "Please enter the product's price" << endl;
    cin >> price;
    cout << "Please enter the product's volume" << endl;
    cin >> volume;
    cout << "Please enter the product's units" << endl;
    cin >> units;
    Supplier s = SupplierRepository::getSupplierbyId(idSupplier);
    int choice;
    cout << "Please enter the product's type" << endl;
    cout << "1. Novel" << endl;
    cout << "2. Textbook" << endl;
    cout << "3. Minecraft" << endl;
    cout << "4. Zelda" << endl;
    cout << "5. Tablet" << endl;
    cout << "6. Smartphone" << endl;
    cout << "7. T-Shirt" << endl;
    cout << "8. Pants" << endl;
    cout << "9. Milk" << endl;
    cout << "10. Cheese" << endl;
    cout << "11. Washing Machine" << endl;
    cout << "12. Fridge" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            {
                Novel novel(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&novel);
                Stock stock(novel, units);
                StockRepository::addStock(stock);
                break;
            }
        case 2:
            {
                Textbook textbook(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&textbook);
                Stock stock(textbook, units);
                StockRepository::addStock(stock);
                break;
            }
        case 3:
            {
                Minecraft minecraft(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&minecraft);
                Stock stock(minecraft, units);
                StockRepository::addStock(stock);
                break;
            }
        case 4:
            {
                Zelda zelda(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&zelda);
                Stock stock(zelda, units);
                StockRepository::addStock(stock);
                break;
            }
        case 5:
            {
                Tablet tablet(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&tablet);
                Stock stock(tablet, units);
                StockRepository::addStock(stock);
                break;
            }
        case 6:
            {
                Smartphone smartphone(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&smartphone);
                Stock stock(smartphone, units);
                StockRepository::addStock(stock);
                break;
            }
        case 7:
            {
                TShirt tshirt(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&tshirt);
                Stock stock(tshirt, units);
                StockRepository::addStock(stock);
                break;
            }
        case 8:
            {
                Pants pants(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&pants);
                Stock stock(pants, units);
                StockRepository::addStock(stock);
                break;
            }
        case 9:
            {
                Milk milk(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&milk);
                Stock stock(milk, units);
                StockRepository::addStock(stock);
                break;
            }
        case 10:
            {
                Cheese cheese(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&cheese);
                Stock stock(cheese, units);
                StockRepository::addStock(stock);
                break;
            }   
        case 11:
            {
                WashingMachine washingmachine(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&washingmachine);
                Stock stock(washingmachine, units);
                StockRepository::addStock(stock);
                break;
            }
        case 12:
            {
                Fridge fridge(ProductRepository::nextIdProduct(), price, volume, s);
                ProductRepository::addProduct(&fridge);
                Stock stock(fridge, units);
                StockRepository::addStock(stock);
                break;
            }
        default:
            break;
                    
    }
}

void DeleteProduct()
{
    cout << "You have selected to delete a product" << endl;
    cout << "Please enter the product's id" << endl;
    int id;
    cin >> id;
    Product* product = ProductRepository::getProductbyId(id);
    ProductRepository::removeProduct(product);
}

void UpdateProduct()
{
    cout << "You have selected to update a product" << endl;
    cout << "Please enter the product's id" << endl;
    int id;
    cin >> id;
    cout << "Please enter what do you want to update" << endl;
    string what,change;
    cin >> what;
    cout << "Please enter the new value" << endl;
    cin >> change;
    ProductRepository::updateProduct(id, what, change);
}

void ProductMenu()
{
    cout << "You are in the Product's menu" << endl;
    string decision;
    do
    {
        cout << "1. Add product" << endl;
        cout << "2. Delete product" << endl;
        cout << "3. Modify product" << endl;
        cout << "4. Show all products" << endl;
        int option;
        cin >> option;
        switch(option)
        {
            case 1:
                CreateProduct();
                break;
            case 2:
                DeleteProduct();
                break;
            case 3:
                UpdateProduct();
                break;
            case 4:
                cout << ProductRepository::getAllProducts() << endl;
                break;
            default:
                break;
        }
        cout << "Do you want to do anything more with Products? yes/no" << endl;
        cin >> decision;
    }while (decision=="yes");
    
    
}

void CreateShipment()
{
    int idCustomer, idTransport, idProduct, quantity;
    string decision;
    cout << "You have selected to add a shipment" << endl;
    cout << "Please enter the shipment's customer ID" << endl;
    cin >> idCustomer;
    cout << "Please enter the shipment's transport ID" << endl;
    cin >> idTransport;
    Customer c = CustomerRepository::getCustomerbyId(idCustomer);
    Transport* t = TransportRepository::getTransportbyId(idTransport);

    list<Packaging> packagingList = list<Packaging>();
    list<Product*> productList = list<Product*>();
    packagingList.push_back(Packaging(t));
    int i=0;
    do
    {
        cout << "Please enter the id and the quantity of the product you want to add" << endl;
        cin >> idProduct >> quantity;
        cin >> quantity;
        Product* p = ProductRepository::getProductbyId(idProduct);
        if(quantity>StockRepository::getStockQuantity(p))
        {
            cout << "There are not enough units in stock" << endl;
            break;
        }
        else
        {
            productList.push_back(p);
            StockRepository::updateStock(p, StockRepository::getStockQuantity(p)-quantity);
            if(StockRepository::getStockQuantity(p)==0)
            {
                ProductRepository::removeProduct(p);
                StockRepository::removeStock(p);
            }
            ProductRepository::updateProduct(p);
            auto it = packagingList.begin();
            advance(it, i);
            if(p->getVolume()*quantity <= it->getCapacity())
            {
                it->addProduct(p);
                it->addToMap(p, quantity);
            }
            else
            {
                packagingList.push_back(Packaging(t));
                i++;
                it++;
                it->addProduct(p);
                it->addToMap(p, quantity);
            }
        }
        cout << "Do you want to add another product? yes/no" << endl;
        cin >> decision;
    } while (decision=="yes");
    Shipment shipment(ShipmentRepository::nextIdShipment(), c, packagingList, t, Fecha());
    ShipmentRepository::addShipment(shipment);
}

void DeleteShipment()
{
    cout << "You have selected to delete a shipment" << endl;
    cout << "Please enter the shipment's id" << endl;
    int id;
    cin >> id;
    Shipment shipment = ShipmentRepository::getShipmentbyId(id);
    ShipmentRepository::removeShipment(shipment);
}

void UpdateShipment()
{
    cout << "You have selected to update a shipment" << endl;
    cout << "Please enter the shipment's id" << endl;
    int id;
    cin >> id;
    cout << "Please enter what do you want to update" << endl;
    string what,change;
    cin >> what;
    cout << "Please enter the new value" << endl;
    cin >> change;
    ShipmentRepository::updateShipment(id, what, change);
}

void ShipmentMenu()
{
    cout << "You are in the Shipment's menu" << endl;
    cout << "1. Add shipment" << endl;
    cout << "2. Delete shipment" << endl;
    cout << "3. Modify shipment" << endl;
    cout << "4. Show all shipments" << endl;
    int option;
    cin >> option;
    switch(option)
    {
        case 1:
                CreateShipment();
                break;
        case 2:
                DeleteShipment();
                break;
        case 3:
                UpdateShipment();
                break;
        case 4:
            cout << ShipmentRepository::getAllShipments() << endl;
            break;
        default:
            break;
    }
}

int main(){
    cout << "Welcome to the Logistic Management Application of the University of Malta" << endl;
    cout << "This is the main class" << endl;
    string decision;
    do
    {
        index();
        int option;
        cin >> option;
        switch(option)
        {
            case 1:
                CustomerMenu();
                break;
            case 2:
                SupplierMenu();
                break;
            case 3:
                TransportMenu();
                break;
            case 4:
                ProductMenu();
                break;
            case 5:
                ShipmentMenu();
                break;
            case 6:
                cout << StockRepository::getAllStock() << endl;
            default:
                break;
        }
        cout << "Do you want to do anything more? yes/no" << endl;
        cin >> decision;
    } while (decision == "yes");
    
    
}