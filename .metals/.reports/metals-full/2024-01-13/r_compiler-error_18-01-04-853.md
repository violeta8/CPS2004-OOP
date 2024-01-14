file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/shipment/Shipment.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 1718
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/shipment/Shipment.java
text:
```scala
package project.shipment;

import project.customer.Customer;
import project.packaging.Packaging;
import project.transport.Transport;
import project.transport.TransportRepository;

import java.util.List;

import java.time.LocalDate;

public class Shipment {
    private int idShipment;
    private Customer customer;
    private List<Packaging> packagings;//this should already have the whole products inside of it
    private Transport transport;
    private LocalDate purchaseDate;
    private LocalDate deliveryDate;

    public Shipment(int idShipment, Customer customer, List<Packaging> packagings, Transport transport, LocalDate purchaseDate) {
        this.idShipment = idShipment;
        this.customer = customer;
        this.packagings = packagings;
        this.transport = transport;
        this.purchaseDate = purchaseDate;
        setDeliveryDate();
    }

    public Shipment( Customer customer, List<Packaging> packagings, Transport transport, LocalDate purchaseDate) {
        this.customer = customer;
        this.packagings = packagings;
        this.transport = transport;
        this.purchaseDate = purchaseDate;
        setDeliveryDate();
    }

    public Shipment() {
        this.idShipment = 0;
        this.customer = null;
        this.packagings = null;
        this.transport = null;
        this.purchaseDate = null;
        this.deliveryDate = null;
    }

    public boolean equals(Shipment shipment) {
        return this.idShipment == shipment.idShipment;
    }

    void updateShipment(String change, String newchange)
    {
        if(change.equals("transport")) {
            this.setTransport(TransportRepository.getTranspor@@tById(Integer.parseInt(newchange)));
        }
        else if(change.equals("delivery date")) {
            this.setDeliveryDate(LocalDate.parse(newchange));
        }
        else {
            throw new IllegalArgumentException("There's no right change");
        }
    }

    public int getIdShipment() {
        return idShipment;
    }

    public void setIdShipment(int idShipment) {
        this.idShipment = idShipment;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public List<Packaging> getPackagings() {
        return packagings;
    }

    public void setPackagings(List<Packaging> packagings) {
        this.packagings = packagings;
    }

    public Transport getTransport() {
        return transport;
    }

    public void setTransport(Transport transport) {
        this.transport = transport;
    }

    public double getTotalCost() {
        double total=0;
        for(Packaging packaging:packagings){
            total+=packaging.getTotalCost()+ transport.getCostPerKM() * (transport.route()+customer.getWarehouseDistance());
        }
        return total;
        
    }

    public LocalDate getPurchaseDate() {
        return purchaseDate;
    }

    public void setPurchaseDate() {
        this.purchaseDate = LocalDate.now();
    }

    public void setPurchaseDate(LocalDate purchaseDate) {
        this.purchaseDate = purchaseDate;
    }

    public void setDeliveryDate(LocalDate deliveryDate) {
        this.deliveryDate = deliveryDate;
    }

    public LocalDate getDeliveryDate() {
        return deliveryDate;
    }

    public void setDeliveryDate() {//there cannot be a wrong deliverydate as it is calculated from the purchase date
        int distance = (int)(customer.getWarehouseDistance()/100);
        if(transport.route()==64){
            this.deliveryDate = purchaseDate.plusDays(1+distance);
        }
        else if(transport.route()==128){
            this.deliveryDate = purchaseDate.plusDays(4+distance);
        }
        else if(transport.route()==256){
            this.deliveryDate = purchaseDate.plusDays(8+distance);
        }
        else{
            throw new IllegalArgumentException("There's no right route");
        }
    }

    @Override
    public String toString() {
        return "Shipment{" +
                "idShipment=" + idShipment +
                ", customer=" + customer.toString() +
                ", packagings=" + packagings.toString() +    
                ", transport=" + transport.toString() +
                ", purchaseDate=" + purchaseDate +
                ", deliveryDate=" + deliveryDate +
                ", totalCost=" + getTotalCost() + "€" + "\n" +
                '}';
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
	scala.meta.internal.pc.HoverProvider$.hover(HoverProvider.scala:34)
	scala.meta.internal.pc.ScalaPresentationCompiler.hover$$anonfun$1(ScalaPresentationCompiler.scala:342)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator