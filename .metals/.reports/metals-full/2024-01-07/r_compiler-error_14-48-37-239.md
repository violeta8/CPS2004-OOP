file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/product/Product.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/product/Product.java
text:
```scala
package project.product;

import project.stock.Stock;
import java.util.Map;

public abstract class Product {
    private int productId;
    private int supplierId;
    private Stock stock;
    private double price;
    
    public Product(int productId, int supplierId, Stock stock, double price) {
        this.supplierId = supplierId;
        this.productId = productId;
        this.stock = stock;
        this.price = price;
    }

    protected Product() {
        productId = 0;
        supplierId = 0;
        stock = null;
        price = 0;
    }

    public void nextId() {
        productId++;
    }

    boolean equals (Product product) {
        return this.productId == product.productId;
    }

    void updateProduct(String change) {
        //make method   
    }

    public int getSupplierId() {
        return supplierId;
    }

    public int getProductId() {
        return productId;
    }

    public Stock getStock() {
        return stock;
    }

    public void setSupplierId(int supplierId) {
        this.supplierId = supplierId;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public void setStock(Stock stock) {
        this.stock = stock;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return price;
    }
    
    public double calculate_discount(int quantity, int month) {
        //make method
        if (month == 1 || month == 2 || month == 12) {
            return 0.9 * quantity * price;
        }
        else if(month == 3 || month == 4 || month == 5) {
            return 0.5 * quantity * price;
        }
        else if(month == 6 || month == 7 || month == 8) {
            return 0.2 * quantity * price;
        }
        else if(month == 9 || month == 10 || month == 11) {
            return 0.1 * quantity * price;
        }
        else {
            return 1;
        }
    }

    public abstract String display_product_info();

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