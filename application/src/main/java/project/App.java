package project;

import java.util.Scanner;
import java.util.List;
import java.time.LocalDate;
import java.util.ArrayList;

import project.customer.*;
import project.customer.CustomerRepository;
import project.packaging.Packaging;
import project.product.*;
import project.product.ProductRepository;
import project.shipment.*;
import project.stock.Stock;
import project.stock.StockRepository;
import project.supplier.*;
import project.supplier.SupplierRepository;
import project.transport.*;
import project.transport.TransportRepository;
import project.transport.truck.Truck;
import project.transport.ship.Ship;
import project.transport.plane.Plane;


/**
 * Hello world!
 *
 */
public class App 
{
    private static Scanner scanner = new Scanner(System.in);
    public static void index(){
        System.out.println("Select what do you want to do:");
        System.out.println( "1. Customers" );
        System.out.println( "2. Product" );
        System.out.println( "3. Suppliers" );
        System.out.println( "4. Transport" );
        System.out.println( "5. Shipments" );
        System.out.println( "6. Stock");
    }

    public static void CustomerMenu(){
        System.out.println( "You are in Customer's MENU" );
        int choice1 = 0;
        System.out.println( "What would you like to do?" );
        System.out.println( "1. Add a customer" );
        System.out.println( "2. Remove a customer" );
        System.out.println( "3. Update a customer" );
        System.out.println( "4. View all customers" );
        System.out.println( "5. View a specific customer" );
        choice1 = scanner.nextInt(); 
        scanner.nextLine();
        switch(choice1) {
            case 1:
                System.out.println( "You have selected to add a customer" );
                System.out.println( "Please enter the customer's name" );
                String name1= scanner.nextLine();
                System.out.println( "Please enter the customer's address" );
                String address = scanner.nextLine();
                System.out.println( "Please enter the customer's email" );
                String email = scanner.nextLine();
                System.out.println( "Please enter the customer's phone number" );
                String phone = scanner.nextLine();
                System.out.println( "Please enter the customer's warehouse distance" );
                double warehouseDistance = scanner.nextDouble();
                scanner.nextLine();
                Customer customer = new Customer(name1, address, email, phone, warehouseDistance);
                CustomerRepository.saveCustomer(customer);
                break;

            case 2: 
                System.out.println( "You have selected to remove a customer" );
                System.out.println( "Please enter the customer's name" );
                String name = scanner.nextLine();
                CustomerRepository.deleteCustomer(CustomerRepository.getCustomerByName(name));
                System.out.println( "The customer has been removed successfully!" );
                break;
            case 3:
                System.out.println( "You have selected to update a customer" );
                System.out.println( "Please enter the customer's id" );
                int id1 = scanner.nextInt();
                scanner.nextLine();
                System.out.println( "Please enter what would you like to change" );
                String change = scanner.nextLine();
                String newchange = scanner.nextLine();
                CustomerRepository.updateCustomer(id1, change, newchange);//todo hacer esto en to los updates
                System.out.println("The customer has been changed successfully!");
                break;
            case 4:
                System.out.println( "You have selected to view all customers" );
                System.out.println( "This is the List of customers that are available at the moment:" );
                System.out.println( CustomerRepository.getAllCustomers() );
                break;
            case 5:
                System.out.println( "You have selected to view a specific customer" );
                System.out.println( "Please enter the customer's id" );
                int id2 = scanner.nextInt();
                scanner.nextLine();
                System.out.println( CustomerRepository.getCustomerById(id2) );
                break;
            default:
                break;
            }
    }

    public static void ProductMenu(){
        System.out.println( "You are in the PRODUCT'S MENU" );
        System.out.println( "What would you like to do?" );
        System.out.println( "1. Add a product" );
        System.out.println( "2. Remove a product" );
        System.out.println( "3. Update a product" );
        System.out.println( "4. View all products" );
        System.out.println( "5. View a specific product" );
        int choice2 = scanner.nextInt();
        scanner.nextLine();
        switch (choice2) {
            case 1:
                System.out.println( "You have selected to add a product" );
                System.out.println("First you need to select the name of the Supplier that will be the one supplying");                        
                String supplier = scanner.nextLine();
                Supplier s= SupplierRepository.getSupplierByName(supplier);
                System.out.println( "Please enter what type of product would you like to add:" );
                System.out.println( "1. Novel" );
                System.out.println( "2. Textbook" );
                System.out.println( "3. Minecraft" );
                System.out.println( "4. Zelda" );
                System.out.println( "5. Tablet" );
                System.out.println( "6. Smartphone" );
                System.out.println( "7. Tshirt" );
                System.out.println( "8. Pants" );
                System.out.println( "9. Milk" );
                System.out.println( "10. Cheese" );
                System.out.println( "11. Washing machine" );
                System.out.println( "12. Fridge" );
                int choice3 = scanner.nextInt();
                scanner.nextLine();
                switch(choice3){
                    case 1:
                        System.out.println( "Please enter the book's genre" );
                        String genre = scanner.nextLine();
                        System.out.println( "Please enter the book's title" );
                        String title = scanner.nextLine();
                        System.out.println( "Please enter the book's price" );
                        double price = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the book's volume");
                        int volume = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the book's units");
                        int units = scanner.nextInt();
                        scanner.nextLine();
                        Novel novel = new Novel(s, volume,price,title,genre);
                        ProductRepository.saveProduct(novel);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),novel);
                        Stock stock = new Stock(novel,units);
                        StockRepository.saveStock(stock);
                        break;

                    case 2:
                        System.out.println( "Please enter the textbook's edition" );
                        int edition = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println( "Please enter the textbook's title" );
                        String title1 = scanner.nextLine();
                        System.out.println( "Please enter the textbook's price" );
                        double price1 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the textbook's volume");
                        int volume1 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the textbook's units");
                        int units1 = scanner.nextInt();
                        scanner.nextLine();
                        Textbook textbook = new Textbook(s,volume1,price1,title1,edition);
                        ProductRepository.saveProduct(textbook);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),textbook);
                        Stock stock1 = new Stock(textbook,units1);
                        StockRepository.saveStock(stock1);
                        break;

                    case 3:
                        System.out.println( "Please enter the game's age restriction" );
                        int ageRestriction = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println( "Please enter the game's platform" );
                        String platform = scanner.nextLine();
                        System.out.println( "Please enter the game's price" );
                        double price2 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the game's packaging volume");
                        int volume2 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the game's units");
                        int units2 = scanner.nextInt();
                        scanner.nextLine();
                        Minecraft minecraft = new Minecraft(s,volume2,price2,platform,ageRestriction);
                        ProductRepository.saveProduct(minecraft);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),minecraft);
                        Stock stock2 = new Stock(minecraft,units2); 
                        StockRepository.saveStock(stock2);
                        break;

                    case 4:
                        System.out.println( "Please enter the game's rating" );
                        String rating = scanner.nextLine();
                        System.out.println( "Please enter the game's platform" );
                        String platform1 = scanner.nextLine();
                        System.out.println( "Please enter the game's price" );
                        double price3 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the game's volume");
                        int volume3 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the game's units");
                        int units3 = scanner.nextInt();
                        scanner.nextLine();
                        Zelda zelda = new Zelda(s,volume3,price3,platform1,rating); 
                        ProductRepository.saveProduct(zelda);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),zelda);
                        Stock stock3 = new Stock(zelda,units3);
                        StockRepository.saveStock(stock3);
                        break;

                    case 5:
                        System.out.println( "Please enter the tablet's brand" );
                        String brand = scanner.nextLine();
                        System.out.println( "Please enter the tablet's energy consumption" );
                        String energyConsumption = scanner.nextLine();
                        System.out.println( "Please enter the tablet's price" );
                        double price4 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the tablet's packaging volume");
                        int volume4 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the tablet's units");
                        int units4 = scanner.nextInt();
                        scanner.nextLine();
                        Tablet tablet = new Tablet(s,volume4,price4,brand,energyConsumption);
                        ProductRepository.saveProduct(tablet);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),tablet);
                        Stock stock4 = new Stock(tablet,units4);
                        StockRepository.saveStock(stock4);
                        break;

                    case 6:
                        System.out.println( "Please enter the smartphone's OS" );
                        String OS = scanner.nextLine();
                        System.out.println( "Please enter the smartphone's energy consumption" );
                        String energyConsumption1 = scanner.nextLine();
                        System.out.println( "Please enter the smartphone's price" );
                        double price5 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the smartphone's packaging volume");
                        int volume5 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the phone's units");
                        int units5 = scanner.nextInt();
                        scanner.nextLine();
                        SmartPhone smartphone = new SmartPhone(s,volume5,price5,energyConsumption1,OS);
                        ProductRepository.saveProduct(smartphone);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),smartphone);
                        Stock stock5 = new Stock(smartphone,units5);
                        StockRepository.saveStock(stock5);
                        break;

                    case 7:
                        System.out.println( "Please enter the tshirt's color" );
                        String color = scanner.nextLine();
                        System.out.println( "Please enter the tshirt's size" );
                        String size = scanner.nextLine();
                        System.out.println( "Please enter the tshirt's price" );
                        double price6 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the tshirt's packaging volume");
                        int volume6 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the tshirt's units");
                        int units6 = scanner.nextInt();
                        scanner.nextLine();
                        TShirt tshirt = new TShirt(s,volume6,price6,color,size);
                        ProductRepository.saveProduct(tshirt);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),tshirt);
                        Stock stock6 = new Stock(tshirt,units6);
                        StockRepository.saveStock(stock6);
                        break;

                    case 8:
                        System.out.println( "Please enter the pants shop's name" );
                        String shopName = scanner.nextLine();
                        System.out.println( "Please enter the pants' size" );
                        String size1 = scanner.nextLine();
                        System.out.println( "Please enter the pants' price" );
                        double price7 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the pants' packaging volume");
                        int volume7 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the pant's units");
                        int units7 = scanner.nextInt();
                        scanner.nextLine();
                        Pants pants = new Pants(s,volume7,price7,shopName,size1);
                        ProductRepository.saveProduct(pants);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),pants);
                        Stock stock7 = new Stock(pants,units7);
                        StockRepository.saveStock(stock7);
                        break;

                    case 9:
                        System.out.println( "Please enter the milk's brand" );
                        String brand1 = scanner.nextLine();
                        System.out.println( "Please enter the milk's expiration date" );
                        String expirationDate = scanner.nextLine();
                        System.out.println( "Please enter the milk's price" );
                        double price8 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the milk's packaging volume");
                        int volume8 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the milk's units");
                        int units8 = scanner.nextInt();
                        scanner.nextLine();
                        Milk milk = new Milk(s,volume8,price8,expirationDate,brand1);
                        ProductRepository.saveProduct(milk);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),milk);
                        Stock stock8 = new Stock(milk,units8);
                        StockRepository.saveStock(stock8);
                        break;

                    case 10:
                        System.out.println( "Please enter the cheese's fat content" );
                        int fatContent = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println( "Please enter the cheese's expiration date" );
                        String expirationDate1 = scanner.nextLine();
                        System.out.println( "Please enter the cheese's price" );
                        double price9 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the cheese's packaging volume");
                        int volume9 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the chesse's units");
                        int units9 = scanner.nextInt();
                        scanner.nextLine();
                        Cheese cheese = new Cheese(s,volume9,price9,expirationDate1,fatContent);
                        ProductRepository.saveProduct(cheese);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),cheese);
                        Stock stock9 = new Stock(cheese,units9);
                        StockRepository.saveStock(stock9);
                        break;
                    case 11:
                        System.out.println( "Please enter the washing machine's volume" );
                        int volume10 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println( "Please enter the washing machine's warranty period" );
                        int warrantyPeriod = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println( "Please enter the washing machine's price" );
                        double price10 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the washing machine's packaging volume");
                        int volume11 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the washing machine's units");
                        int units10 = scanner.nextInt();
                        scanner.nextLine();
                        WashingMachine washingMachine = new WashingMachine(s,volume11,price10,volume10,warrantyPeriod);
                        ProductRepository.saveProduct(washingMachine);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),washingMachine);
                        Stock stock10 = new Stock(washingMachine,units10);
                        StockRepository.saveStock(stock10);
                        break;
                    case 12:
                        System.out.println( "Please enter the fridge's energy consumption" );
                        String energyConsumption2 = scanner.nextLine();
                        System.out.println( "Please enter the fridge's warranty period" );
                        int warrantyPeriod1 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println( "Please enter the fridge's price" );
                        double price11 = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Please enter the fridge's packaging volume");
                        int volume12 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the fridge's units");
                        int units11 = scanner.nextInt();
                        scanner.nextLine();
                        Fridge fridge = new Fridge(s,volume12,price11,warrantyPeriod1,energyConsumption2);
                        ProductRepository.saveProduct(fridge);
                        SupplierRepository.updateSupplier(s.getIdSupplier(),fridge);
                        Stock stock11 = new Stock(fridge,units11);
                        StockRepository.saveStock(stock11);
                        break;
                
                    default:
                        break;
                    
                    
                }
                break;
                case 2:
                    System.out.println( "You have selected to remove a product" );
                    System.out.println( "Please enter the product's id" );
                    int id = scanner.nextInt();
                    scanner.nextLine();
                    ProductRepository.deleteProduct(id);
                    System.out.println( "The product has been removed successfully!" );
                    break;
                case 3:
                    System.out.println( "You have selected to update a product" );
                    System.out.println( "Please enter the product's id" );
                    int id1 = scanner.nextInt();
                    scanner.nextLine();
                    System.out.println( "Please enter what would you like to change" );
                    String change = scanner.nextLine();
                    System.out.println( "Please enter the new value" );
                    String newchange = scanner.nextLine();
                    try{
                        ProductRepository.updateProduct(id1, change,newchange);
                    }catch(IllegalAccessError e){
                        System.out.println(e.getMessage());
                    }
                    System.out.println("The product has been changed successfully!");
                    break;
                case 4:
                    System.out.println( "You have selected to view all products" );
                    System.out.println( "This is the List of products that are available at the moment:" );
                    System.out.println( ProductRepository.getAllProducts() );
                    break;
        }
    }

    public static void SupplierMenu(){
        System.out.println( "You are in the SUPPLIER'S MENU" );
        System.out.println( "What would you like to do?" );
        System.out.println( "1. Add a supplier" );
        System.out.println( "2. Remove a supplier" );
        System.out.println( "3. Update a supplier" );
        System.out.println( "4. View all suppliers" );
        System.out.println( "5. View a specific supplier" );
        int choice4 = scanner.nextInt();
        scanner.nextLine();
        switch (choice4) {
            case 1:
                System.out.println( "You have selected to add a supplier" );
                System.out.println( "Please enter the supplier's name" );
                String name = scanner.nextLine();
                System.out.println( "Please enter the supplier's address" );
                String address = scanner.nextLine();
                System.out.println( "Please enter the supplier's email" );
                String email = scanner.nextLine();
                System.out.println( "Please enter the supplier's phone number" );
                String phone = scanner.nextLine();
                Supplier supplier = new Supplier(SupplierRepository.nextIdSupplier(),name, address, email, phone);
                SupplierRepository.saveSupplier(supplier);
                break;
            case 2:
                System.out.println( "You have selected to remove a supplier" );
                System.out.println( "Please enter the supplier's name" );
                String nameSup = scanner.nextLine();
                SupplierRepository.deleteSupplier(SupplierRepository.getSupplierByName(nameSup).getIdSupplier());
                System.out.println( "The supplier has been removed successfully!" );
                break;
            case 3:
                System.out.println( "You have selected to update a supplier" );
                System.out.println( "Please enter the supplier's id" );
                int id1 = scanner.nextInt();
                scanner.nextLine();
                System.out.println( "Please enter what would you like to change" );
                String change = scanner.nextLine();
                System.out.println( "Please enter the new value" );
                String newchange = scanner.nextLine();
                try{
                    SupplierRepository.updateSupplier(id1, change,newchange);
                }catch(IllegalAccessError e){
                    System.out.println(e.getMessage());//todo hace esto en to laos
                }
                System.out.println("The supplier has been changed successfully!");
                break;
            case 4:
                System.out.println( "You have selected to view all suppliers" );
                System.out.println( "This is the List of suppliers that are available at the moment:" );
                System.out.println( SupplierRepository.getAllSuppliers() );
                break;
            case 5:
                System.out.println( "You have selected to view a specific supplier" );
                System.out.println( "Please enter the supplier's name");
                String nameSupp = scanner.nextLine();
                System.out.println( SupplierRepository.getSupplierByName(nameSupp).display_supplier_info() );
                break;
            default:
                break;
        }
    }

    public static void TransportMenu(){
        System.out.println( "You are in the TRANSPORT'S MENU" );
        System.out.println( "What would you like to do?" );
        System.out.println( "1. Add a transport" );
        System.out.println( "2. Remove a transport" );
        System.out.println( "3. Update a transport" );
        System.out.println( "4. View all transports" );
        System.out.println( "5. View a specific transport" );
        int choice5 = scanner.nextInt();
        scanner.nextLine();
        switch (choice5) {
        
            case 1:
                System.out.println( "You have selected to add a transport" );
                System.out.println( "Please enter the transport's type" );
                System.out.println( "1. Truck" );
                System.out.println( "2. Ship" );
                System.out.println( "3. Plane" );
                int type = scanner.nextInt();
                scanner.nextLine();
                switch(type){
                    case 1:
                        System.out.println("Please enter the truck's license plate");
                        String plate = scanner.nextLine();
                        System.out.println("Please enter the truck's cost per km");
                        int costPerKM = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the truck's speed");
                        double speed = scanner.nextDouble();
                        scanner.nextLine();
                        Truck truck = new Truck(TransportRepository.nextIdTransport(), costPerKM, speed, plate);
                        TransportRepository.saveTransport(truck);
                        break;
                    case 2:
                        System.out.println("Please enter the ship's license plate");
                        String plate1 = scanner.nextLine();
                        System.out.println("Please enter the ship's cost per km");
                        int costPerKM1 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the ship's speed");
                        double speed1 = scanner.nextDouble();
                        scanner.nextLine();
                        Ship ship = new Ship(TransportRepository.nextIdTransport(), costPerKM1, speed1, plate1);
                        TransportRepository.saveTransport(ship);
                        break;
                    case 3:
                        System.out.println("Please enter the plane's license plate");
                        String plate2 = scanner.nextLine();
                        System.out.println("Please enter the plane's cost per km");
                        int costPerKM2 = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Please enter the plane's speed");
                        double speed2 = scanner.nextDouble();
                        scanner.nextLine();
                        Plane plane = new Plane(TransportRepository.nextIdTransport(), costPerKM2, speed2, plate2);
                        TransportRepository.saveTransport(plane);
                        break;
                    default:
                        break;
                }
                break;
                
            case 2:
                System.out.println( "You have selected to remove a transport" );
                System.out.println( "Please enter the transport's id" );
                int id = scanner.nextInt();
                scanner.nextLine();
                TransportRepository.deleteTransport(id);
                System.out.println( "The transport has been removed successfully!" );
                break;
            case 3:
                System.out.println( "You have selected to update a transport" );
                System.out.println( "Please enter the transport's id" );
                int id1 = scanner.nextInt();
                scanner.nextLine();
                System.out.println( "Please enter what would you like to change" );
                String change = scanner.nextLine();
                System.out.println( "Please enter the new value" );
                
                String newchange = scanner.nextLine();
                try{
                    SupplierRepository.updateSupplier(id1, change,newchange);
                }catch(IllegalAccessError e){
                    System.out.println(e.getMessage());
                }
                System.out.println("The transport has been changed successfully!");
                break;
            case 4:
                System.out.println( "You have selected to view all transports" );
                System.out.println( "This is the List of transports that are available at the moment:" );
                System.out.println( TransportRepository.getAllTransports() );
                break;
            case 5:
                System.out.println( "You have selected to view a specific transport" );
                System.out.println( "Please enter the transport's id" );
                int id2 = scanner.nextInt();
                scanner.nextLine();
                System.out.println( TransportRepository.getTransportById(id2) );
                break;
            default:
                break;
        }
    }

    public static void ShipmentMenu(){
        System.out.println( "You are in the SHIPMENT'S MENU" );
        System.out.println( "What would you like to do?" );
        System.out.println( "1. Add a shipment" );
        System.out.println( "2. Cancel a shipment" );
        System.out.println( "3. Update a shipment" );
        System.out.println( "4. View all shipments" );
        int choice6 = scanner.nextInt();
        scanner.nextLine();
        switch (choice6) {
            case 1:
                System.out.println( "You have selected to add a shipment" );
                System.out.println("Please enter the shipment's transport id");
                int transportId = scanner.nextInt();
                scanner.nextLine();
                Transport transport = TransportRepository.getTransportById(transportId);
                //the packaging volume will be based on the transport's type
                List<Packaging> packagingList = new ArrayList<Packaging>();
                System.out.println("Please enter the shipment's customer id");
                int customerId = scanner.nextInt();
                scanner.nextLine();
                Customer customer = CustomerRepository.getCustomerById(customerId);
                List<Product> products = new ArrayList<Product>();
                packagingList.add(new Packaging(transport));
                int i=0;
                do{
                    System.out.println("Please enter the id and the quantity of the products you want to add to the shipment");
                    int productid = scanner.nextInt();
                    scanner.nextLine();
                    int quantity = scanner.nextInt();//todo poner esto en el getTotalCost() de packaging
                    scanner.nextLine();
                    Product product = ProductRepository.getProductById(productid);
                    if(quantity>StockRepository.getStockQuantity(product)){
                        System.out.println("The quantity you entered is bigger than the available stock of the product");
                    }
                    else{
                        products.add(product);
                        StockRepository.updateStock(product,StockRepository.getStockQuantity(product)-quantity);
                        if(StockRepository.getStockQuantity(product)==0){
                        ProductRepository.deleteProduct(product.getProductId());
                        StockRepository.deleteStock(product);
                        }
                        ProductRepository.updateProduct(product);
                        if(product.getVolume()*quantity<=packagingList.get(i).getCapacity()){
                            packagingList.get(i).addProduct(product);
                        }
                        else{
                            packagingList.add(new Packaging(transport));
                            i++;
                            packagingList.get(i).addProduct(product);
                        }
                        
                    }
                    
                System.out.println("Would you like to add more products? Please write yes");
                }while(scanner.nextLine().equals("yes"));
                Shipment shipment = new Shipment(customer, packagingList , transport, LocalDate.now());
                ShipmentRepository.saveShipment(shipment);
                break;

            case 2:
                System.out.println("Please enter the shipment's id");
                ShipmentRepository.getAllShipments();
                int id = scanner.nextInt();
                scanner.nextLine();
                try{
                    ShipmentRepository.deleteShipment(id);
                }catch(IllegalAccessError e){
                    System.out.println(e.getMessage());
                }
                break;

            case 3: 
                System.out.println("Please enter the shipment's id");
                int id1 = scanner.nextInt();
                scanner.nextLine();
                System.out.println("Please enter what would you like to change");
                String change = scanner.nextLine();
                System.out.println("Please enter the new value");
                String newchange = scanner.nextLine();
                try{
                    ShipmentRepository.updateShipment(id1, change, newchange);
                }catch(IllegalAccessError e){
                    System.out.println(e.getMessage());
                }
                break;
            case 4:
                System.out.println( "You have selected to view all shipments" );
                System.out.println( "This is the List of shipments that are available at the moment:" );
                System.out.println( ShipmentRepository.getAllShipments() );
                break;
        
        }
    }

    public static void StockMenu(){
        System.out.println("You have selected the Stock option");
        System.out.println("What would you like to do?");
        System.out.println("1. View all the stock");
        System.out.println("2. View a specific product's stock");
        System.out.println("3. Increase product stock");
        int choice7 = scanner.nextInt();
        scanner.nextLine();
        switch(choice7){
            case 1:
                System.out.println( "You have selected to view all the stock" );
                System.out.println( "This is the List of stock that is available at the moment:" );
                System.out.println( StockRepository.getAllStocks() );
                break;
            case 2:
                System.out.println( "You have selected to view a specific product's stock" );
                System.out.println( "Please enter the product's id" );
                int id = scanner.nextInt();
                scanner.nextLine();
                Stock s = StockRepository.getStockById(id);
                System.out.println( s.display_stock_info() );
                break;
            case 3:
                System.out.println( "You have selected to increase product stock" );
                System.out.println( "Please enter the product's id" );
                int id1 = scanner.nextInt();
                scanner.nextLine();
                System.out.println( "Please enter the quantity you want to add" );
                int quantity = scanner.nextInt();
                scanner.nextLine();
                StockRepository.updateStock(ProductRepository.getProductById(id1),quantity);
                break;
            default:
                break;
        }
    }

    public static void main( String[] args )
    {        
        System.out.println( "Welcome to the Logistics Management Application OF THE UNIVERSITY OF MALTA" );
        System.out.println( "This is the main class" );
        System.out.println( "In here you will be able to see everything" );

        do{
            index();
            int choice = 0;
            choice = scanner.nextInt();
            scanner.nextLine();
            switch(choice) {
                case 1:
                    do{
                        CustomerMenu();
                        System.out.println( "Would you like to do anything more with Customers? Please write yes" );
                    }while(scanner.nextLine().equals("yes"));
                    break;
                    
                case 2:
                    do{
                        ProductMenu();
                        System.out.println( "Would you like to do anything more with Products? Please write yes" );
                    }while(scanner.nextLine().equals("yes"));
                    break;

                case 3: 
                    do{
                        SupplierMenu();
                        System.out.println( "Would you like to do anything more with Suppliers? Please write yes" );
                    }while(scanner.nextLine().equals("yes"));  
                    break;  
            
                case 4:
                    do{
                        TransportMenu();
                        System.out.println( "Would you like to do anything more with Transports? Please write yes" );
                    }while(scanner.nextLine().equals("yes"));
                    break;
                case 5:
                    do{
                        ShipmentMenu();
                        System.out.println( "Would you like to do anything more with Shipments? Please write yes" );
                    }while(scanner.nextLine().equals("yes"));
                    break;
                case 6: 
                    do{
                        StockMenu();
                        System.out.println( "Would you like to do anything more with Stock? Please write yes" );
                    }while(scanner.nextLine().equals("yes"));
                    break;
                }
            
            System.out.println( "Would you like to do anything more with the application? Please write yes" );
        }while(scanner.nextLine().equals("yes"));
        scanner.close();
    }
}

