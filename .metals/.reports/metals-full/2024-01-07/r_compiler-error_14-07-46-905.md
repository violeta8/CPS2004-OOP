file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/Customer.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/Customer.java
text:
```scala
package project.customer;

import java.util.Map;
import java.util.List;
import project.product.*;
import project.shipment.*;
import java.util.Scanner;

public class Customer {
    private int idCustomer;
    private static int nextId=1;
    private String name;
    private String address;
    private String email;
    private String phone;
    private double warehouseDistance;
    private List<Product> idProducts;
    private List<Shipment> idShipments;//because for each list of products ww'll have a list of packaging

    public Customer(int idCustomer, String name, String address, String email, String phone, double warehouseDistance, List<Product> idProducts, List<Shipment> idShipments) {
        this.idCustomer = nextId++;
        this.name = name;
        this.address = address;
        this.email = email;
        this.phone = phone;
        this.warehouseDistance = warehouseDistance;
        this.idProducts = idProducts;
        this.idShipments = idShipments;
    }

    protected Customer() {
        this.idCustomer = 0;
        this.name = "";
        this.address = "";
        this.email = "";
        this.phone = "";
        this.warehouseDistance = 0;
        this.idProducts = null;
        this.idShipments = null;
    }

    public Customer(String name2, String address2, String email2, String phone2, double warehouseDistance2) {
        this.idCustomer = nextId++;
        this.name = name2;
        this.address = address2;
        this.email = email2;
        this.phone = phone2;
        this.warehouseDistance = warehouseDistance2;
        this.idProducts = null;
        this.idShipments = null;
	}

	public boolean equals(Customer customer) {
        return this.name.equals(customer.name) && this.address.equals(customer.address) && this.email.equals(customer.email) && this.phone.equals(customer.phone) && this.warehouseDistance == customer.warehouseDistance;
    }

    void updateCustomer(String) {
        Scanner newinfo = new Scanner(System.in);
        if (info.containsKey("name")) {
            this.name = newinfo.nextLine();
        }
        if (info.containsKey("address")) {
            this.address = newinfo.nextLine();
        }
        if (info.containsKey("email")) {
            this.email = newinfo.nextLine();
        }
        if (info.containsKey("phone")) {
            this.phone = newinfo.nextLine();
        }
        if (info.containsKey("warehouseDistance")) {
            this.warehouseDistance = newinfo.nextDouble();
            newinfo.nextLine();
        }
    }

    public int getIdCustomer() {
        return idCustomer;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public String getEmail(){
        return email;
    }

    public String getPhone(){
        return phone;
    }

    public double getWarehouseDistance(){
        return warehouseDistance;
    }

    public List<Product> getIdProducts(){
        return idProducts;
    }

    public List<Shipment> getidShipments(){
        return idShipments;
    }

    public void setIdCustomer(int idCustomer) {
        this.idCustomer = idCustomer;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAddress(String address){
        this.address = address;
    }

    public void setEmail(String email){
        this.email = email;
    }

    public void setPhone(String phone){
        this.phone = phone;
    }

    public void setWarehouseDistance(double warehouseDistance){
        this.warehouseDistance = warehouseDistance;
    }

    public void setIdProducts(List<Product> idProducts){
        this.idProducts = idProducts;
    }

    public void setidShipments(List<Shipment> idShipments){
        this.idShipments = idShipments;
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