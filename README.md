# CPS2004-OOP
# UNIVERSITY OF MALTA
## OBJECT ORIENTATED PROGRAMMING
derivables for the class of Object Orientated Programming

# 1.	Classes
In this case we have lots of classes but as defined in the assignment I’ll just talk about the important information and methods of them. Each instance of each class will have an id that will be automatically put from 0…N.

•	Both classes Supplier and Customer have the same attributes but, Customer it’s related to Shipments and Supplier to Product. Both classes also have Repositories which are implemented to handle each one of the instances of these two classes.

•	Transport class it’s an abstract class made so that its children will be concrete classes that inherits from this class, in this case Transport class have 3 children:

    o	Truck class will store all the einformation of the Transport and a string that will save the plate of the truck.

    o	Plane class will store all the information of the Transport and a string that will save the name of the plane.

    o	Ship class will store all the information of the Transport and a string that will save the name of the ship.

This Transport class also have a Repository for us to keep count of the created objects. The method that makes this class an abstract class it’s route() function, which gives up the kilometers that each transport goes through.

•	Product class has lots of specification and children, it’s indeed an abstract class, as it has the display_product_info() declared as pure abstract method which will be implemented in the concrete subclasses I’ll talk about later on, and apart from this abstract polymorphic method we also have the calculate_discount(quantity, month) method that is also polymorphic as it’s a method that all the coming classes will have. This class also have a Repository which is implemented to handle each one of the instances created later on as the class is abstract and cannot be instantiated by itself. This class also come with 6 abstract subclasses:

Food class that has an attribute that is its expiry date saved in a string, this class splits into two concrete classes that are:
    
    - Milk  that has an attribute (a string) that saves the brand of the Milk.
    
    - Cheese this one has an attribute (an int) that will save up the fat content of the cheese.

Book has an attribute that will save up the tittle of the book, this class will be split into:
    
    - Novel this class has an attribute that saves the genre of the novel as a string.
    
    - Textbook has an attribute that stores the edition of the book, this attribute is saved in an interger

HomeAppliance class that has a string that saves up the warranty period each object has, this class will be split into:
    
    - WashingMachine class has an attribute that saves up the capacity of this object.
    
    - Fridge class has a string that saves up the energy consumption that each object of fridge will consume.

Clothing class has a string that saves the size of each piece of clothing that will be later instantiated:
    
    - TShirt stores in an attribute the color (string) of this tshirt the user will create.
    
    - Pants this class will save the shop that the pants will be bought in a string.

Electronic class has a string that stores the energy consumption of each object created these two concrete subclasses of this one could be:
        	
            - Tablet that has a string as an attribute that will store the brand of each object.

        	- Smartphone has a string that will save up the operative 
            system of each object.
    
ComputerGame class has a string that stores the platform in which each game could be played at, these concrete subclasses games are:

    	- Minecraft that has an int that will save the age restriction of each object.
        
        - Zelda that has a string that will save up the ratings of every object that will be created.

•	Stock class has as attributes a Product and a quantity available of each Product created in the Stock. It also has a repository in which we will store every product next to its available units.

•	Packaging class has the attribute of capacity and cost also has a list of Products that saves the information of every product that will be sent to the Shipment class which I’ll cover next time.

•	Shipment class has lots of characteristics, it has 2 attributes that will be created depending on the date you decide to ‘create a shipment’. This class also have a list of packaging has it will be a shipment of a variety of products.

# 2.	Repositories
There are repositories for each class implemented in the application:
•	Customer and Supplier repositories are created to keep count on the objects created of each type, also to save, update, delete and show all the information store in them.

•	Stock repository is created to keep count of all the products and its quantity store in one place.

•	Packaging repository is going to store the information to keep updated the id of each instance of type packaging.

•	Transport repository will store the information of each type of transport, no matter what type it is (Truck, Plane, Ship), it will store the information and handle its update, save, delete and show the information of all the transport stored.

•	Product repository will have the same approach as transport but with their respective product subtypes (Novel, Textbook, Cheese, Milk, TShirt, Pants, WashingMachine, Fridge, Tablet, Smartphone, Minecraft and Zelda)

•	Shipment repository will store all the shipments created, this repository will handle the saving, updating, delete, and show all the shipments made.

# Run and compile
To run the application you will need to have installed the latest version of Java and Maven, then you will need to open the terminal and go to the directory where the project is located and type the following command:
```bash
mvn exec:java
```

After this you will be able to use the application.

In the C++ version of the application you will need to have installed the latest version of C++ and CMake, then you will need to open the terminal and go to the directory where the project is located and type the following command:
```bash
cmake .
```
This will create the makefile which means that you will be able to compile the project.
After this you will need to type the following command:
```bash
make
```
This will compile the project and create the executable file.

After this you will need to type the following command:
```bash
./project
```
After this you will be able to use the application.
To clean the project you will need to type the following command:
```bash
make clean
```
