file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Pants.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 573
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Pants.java
text:
```scala
package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;
public class Pants extends Clothing{
    private String shop;

    public Pants(Supplier supplierId, int volume, double price, String size, String shop) {
        super(supplierId, volume, price, size);
        this.shop = shop;
    }

    protected Pants() {
        super();
        shop = null;
    }

    boolean equals(Pants pants){
        return this.shop.equals(pants.shop);
    }

    @Override
    public void updateProduct(int id,String chang@@e,String pantsInfo) {
        super.updateProduct(id, change, pantsInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("shop")) {
            this.setShop(pantsInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getShop() {
        return shop;
    }

    public void setShop(String shop){
        this.shop = shop;
    }

    @Override
    public String display_product_info() {
        return "Pants{" +
                "shop='" + shop + '\'' +
                ", size='" + getSize() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
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