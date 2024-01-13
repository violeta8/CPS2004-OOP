file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Zelda.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 297
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Zelda.java
text:
```scala
package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Zelda extends ComputerGame{
    private String rating;

    public Zelda(Supplier supplierId, int volume, double price, String platform, String rating) {
        super(supplier@@Id, volume, price, platform);
        this.rating = rating;
    }

    protected Zelda(){
        super();
        rating = "";
    }

    boolean equals(Zelda zelda){
        return this.rating == zelda.rating;
    }

    @Override
    public void updateProduct(int id,String change,String zeldaInfo) {
        super.updateProduct(id, change, zeldaInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("rating")) {
            this.setRating(zeldaInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getRating() {
        return rating;
    }

    public void setRating(String rating){
        this.rating = rating;
    }

    @Override
    public String display_product_info() {
        return "Zelda{" +
                "rating='" + rating + '\'' +
                ", platform='" + getPlatform() + '\'' +
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