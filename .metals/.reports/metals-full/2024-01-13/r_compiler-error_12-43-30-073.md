file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/packaging/Packaging.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 516
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/packaging/Packaging.java
text:
```scala
package project.packaging;

import java.util.List;
import java.util.ArrayList;
import java.time.LocalDate;

import project.product.*;
import project.transport.*;
import project.transport.truck.Truck;
import project.transport.ship.Ship;
import project.transport.plane.Plane;

public class Packaging {
    private int idPackaging;
    private int capacity;//this will depend on the type of transport
    private int cost;
    private List<Product> products;

    public Packaging(int idPackaging, int@@ capacity, int cost, List<Product> products) {
        this.idPackaging = idPackaging;
        this.capacity = capacity;
        this.cost = cost;
        this.products = products;
    }

    public Packaging(int capacity){
        this.idPackaging = PackagingRepository.nextIdPackaging();
        this.capacity = capacity;
        this.cost = 1;
        this.products = new ArrayList<Product>();
    }

    public Packaging(Transport t) {
        this.idPackaging = PackagingRepository.nextIdPackaging();
        this.cost = 3;
        this.products = new ArrayList<Product>();
        if(t instanceof Truck){
            this.capacity = 50;
            this.cost = 3;
        }
        else if(t instanceof Ship){
            this.capacity = 80;
            this.cost = 1;
        }
        else if(t instanceof Plane){
            this.capacity = 100;
            this.cost = 2;
        }
    }

    public Packaging() {
        this.idPackaging = 0;
        this.capacity = 16;
        this.cost = 2;
        this.products = null;
    }

    public boolean equals(Packaging packaging) {
        return this.capacity == packaging.capacity && this.cost == packaging.cost;
    }

    void updatePackaging(String change, String newchange) {
        if (change.equals("capacity")) {
            this.capacity = Integer.parseInt(newchange);
        } else if (change.equals("cost")) {
            this.cost = Integer.parseInt(newchange);
        }
    }

    public void addProduct(Product product) {
        if (product.getVolume() <= remaining()) {
            products.add(product);
        } else {
            System.out.println("Not enough space");
        }
    }

    public int getCapacity() {
        return capacity;
    }

    public int remaining() {
        int sum = 0;
        for (Product product : products) {
            sum += product.getVolume();
        }
        return capacity - sum;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
        if (this.capacity < this.cost) {
            this.cost = this.capacity;
        }
    }

    public int getcost() {
        return cost;
    }

    public void setcost(int cost) {
        this.cost = cost;
    }

    public double getTotalCost() {
        for(Product product:products){
            cost+=product.getPrice()*product.calculate_discount(product.get, LocalDate.now().getMonthValue());
        }
        if(capacity<50){
            return 5+cost;
        }
        else if(capacity<80){
            return 4+cost;
        }
        else {//if(capacity<100)
            return 1+cost;
        }
    }

    public String toString() {
        String list = "";
        for (Product product : products) {
            list += product.display_product_info() + ", ";
        }
        return list;
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