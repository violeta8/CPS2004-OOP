file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/TShirt.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 228
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/TShirt.java
text:
```scala
package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class TShirt extends Clothing{
    private String color;

    public TShirt(Supplier supplierId, int volume, doubl@@e price, String size, String color) {
        super(supplierId, volume, price, size);
        this.color = color;
    }

    protected TShirt() {
        super();
        color = null;
    }

    boolean equals(TShirt tShirt){
        return this.color.equals(tShirt.color);
    }

    @Override
    public void updateProduct(int id,String change,String tShirtInfo) {
        super.updateProduct(id, change, tShirtInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("color")) {
            this.setColor(tShirtInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color){
        this.color = color;
    }

    @Override
    public String display_product_info() {
        return "TShirt{" +
                "color='" + color + '\'' +
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