file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Milk.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 300
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Milk.java
text:
```scala
package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Milk extends Food{
    private String brand;

    public Milk(Supplier supplierId, int volume, double price, String expirationDate, String brand) {
        super(supplierId, volum@@e, price, expirationDate);
        this.brand = brand;
    }

    protected Milk() {
        super();
        brand = null;
    }

    boolean equals(Milk milk){
        return this.brand.equals(milk.brand);
    }

    @Override
    public void updateProduct(int id,String change,String milkInfo) {
        super.updateProduct(id, change, milkInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("brand")) {
            this.setBrand(milkInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand){
        this.brand = brand;
    }

    @Override
    public String display_product_info() {
        return "Milk{" +
                "brand='" + brand + '\'' +
                ", expirationDate='" + getExpirationDate() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" +  StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
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