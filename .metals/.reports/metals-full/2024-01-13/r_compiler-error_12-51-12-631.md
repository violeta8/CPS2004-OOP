file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/stock/Stock.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 656
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/stock/Stock.java
text:
```scala
package project.stock;

import project.product.Product;

public class Stock {
    private int quantity;//first int is product id, second int is quantity
    private Product product;

    public Stock(Product product, int quantity) {
        this.quantity = quantity;
        this.product = product;
    }

    public Stock() {
        this.quantity = 0;
        this.product = null;
    }

    public Product getProduct() {
        return product;
    }

    public void addProduct(Product product, int quantity) {
        this.product = product;
        this.quantity += quantity;
    }

    public void removeProduct(Product pr@@oduct, int quantity) {
        this.product = product;
        this.quantity -= quantity;
    }

    public void updateStock(int q){
        this.quantity = q;
    }

    public int getAvailableStock(Product product) {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public void setProduct(Product product) {
        this.product = product;
    }

    public int getQuantity() {
        return quantity;
    }

    public String display_stock_info() {
        return "Stock{" +
                "quantity=" + quantity +
                ", product=" + product.display_product_info() +
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