file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/App.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/App.java
text:
```scala
package project;

import java.util.Scanner;
import java.util.Map;

import project.customer.*;
import project.product.*;
import project.shipment.*;
import project.supplier.*;
import project.stock.*;
import project.transport.*;


/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println( "Welcome to the Logistics Management Application OF THE UNIVERSITY OF MALTA" );
        System.out.println( "This is the main class" );
        System.out.println( "In here you will be able to see everything" );
        System.out.println( "You will be able to see the stock, the customers, the suppliers, the products, the shipments, and transports!" );
        System.out.println( "You will also be able to add, remove, update, and view all of these!" );
        System.out.println( "BUT first you will need to select which one you want to do:" );
        System.out.println( "1. Customers" );
        System.out.println( "2. Product" );
        System.out.println( "3. Suppliers" );
        System.out.println( "4. Stock" );
        System.out.println( "5. Shipments" );

        CustomerRepository customerRep = new CustomerRepositoryMem();
        ProductRepository productRep = new ProductRepositoryMem();

        
        int choice = 0;
        Scanner scanner = new Scanner(System.in);
        choice = scanner.nextInt(); 
        scan
        switch(choice) {
            case 1:
                System.out.println( "You are in Customer's MENU" );

                

                int choice1 = 0;
                System.out.println( "What would you like to do?" );
                System.out.println( "1. Add a customer" );
                System.out.println( "2. Remove a customer" );
                System.out.println( "3. Update a customer" );
                System.out.println( "4. View all customers" );
                System.out.println( "5. View a specific customer" );
                choice1 = scanner.nextInt(); 
                switch(choice1) {
                    case 1:
                        System.out.println( "You have selected to add a customer" );
                        System.out.println( "Please enter the customer's name" );
                        //get the name in a string

                        String name1= scanner.nextLine();
                        System.out.println( "Please enter the customer's address" );
                        String address = scanner.nextLine();
                        System.out.println( "Please enter the customer's email" );
                        String email = scanner.nextLine();
                        System.out.println( "Please enter the customer's phone number" );
                        String phone = scanner.nextLine();
                        System.out.println( "Please enter the customer's warehouse distance" );
                        double warehouseDistance = scanner.nextDouble();
                        Customer customer = new Customer(name1, address, email, phone, warehouseDistance);
                        customerRep.saveCustomer(customer);
                        break;

                    case 2: 
                        System.out.println( "You have selected to remove a customer" );
                        System.out.println( "Please enter the customer's name" );
                        String name = scanner.nextLine();
                        customerRep.getCustomerByName(name);
                        System.out.println( "The customer has been removed successfully!" );
                        break;
                    case 3:
                        System.out.println( "You have selected to update a customer" );
                        System.out.println( "Please enter the customer's id" );
                        int id1 = scanner.nextInt();
                        System.out.println( "Please enter what would you like to change" );
                        String change = scanner.nextLine();
                        System.out.println( "Please enter the new value" );
                        String newValue = scanner.nextLine();
                        customerRep.updateCustomer(id1, change, newValue);
                        System.out.println("The customer has been changed successfully!");
                        break;
                    case 4:
                        System.out.println( "You have selected to view all customers" );
                        System.out.println( "This is the List of customers that are available at the moment:" );
                        System.out.println( customerRep.getAllCustomers() );
                        break;
                    case 5:
                        System.out.println( "You have selected to view a specific customer" );
                        System.out.println( "Please enter the customer's id" );
                        int id2 = scanner.nextInt();
                        System.out.println( customerRep.getCustomerById(id2) );
                        break;
                    default:
                        break;
                }

                System.out.println( "Would you like to do anything more with Customers? Please write yes" );
                
            
                        
                
                case 2:
                    System.out.println( "You have selected to remove a product" );
                    System.out.println( "Please enter the product type" );
                    String type = scanner.nextLine();
                    switch (type) {
                        case "novel":
                                System.out.println( "Please enter the book's genre" );
                                String genre = scanner.nextLine();
                                

                        case "textbook":

                        case "minecraft":

                        case "zelda":

                        case "tablet":

                        case "smartphone":

                        case "tshirt":

                        case "pants":

                        case "milk":

                        case "cheese":

                        case "washing machine":

                        case "fridge":

                            break;
                    
                        default:
                            break;
                    }
        }    
        scanner.close();   
         
    }
}

```



#### Error stacktrace:

```
scala.collection.Iterator$$anon$19.next(Iterator.scala:973)
	scala.collection.Iterator$$anon$19.next(Iterator.scala:971)
	scala.collection.mutable.MutationTracker$CheckedIterator.next(MutationTracker.scala:76)
	scala.collection.IterableOps.head(Iterable.scala:222)
	scala.collection.IterableOps.head$(Iterable.scala:222)
	scala.collection.AbstractIterable.head(Iterable.scala:933)
	dotty.tools.dotc.interactive.InteractiveDriver.run(InteractiveDriver.scala:168)
	scala.meta.internal.pc.MetalsDriver.run(MetalsDriver.scala:45)
	scala.meta.internal.pc.PcCollector.<init>(PcCollector.scala:45)
	scala.meta.internal.pc.PcSemanticTokensProvider$Collector$.<init>(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector$lzyINIT1(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.provide(PcSemanticTokensProvider.scala:90)
	scala.meta.internal.pc.ScalaPresentationCompiler.semanticTokens$$anonfun$1(ScalaPresentationCompiler.scala:99)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator