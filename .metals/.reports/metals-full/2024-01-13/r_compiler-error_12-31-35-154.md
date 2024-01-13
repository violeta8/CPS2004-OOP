file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Minecraft.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 24
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Minecraft.java
text:
```scala
package project.product;@@

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Minecraft extends ComputerGame{
    private int ageRestriction;

    public Minecraft(Supplier supplierId, int volume, double price, String platform, int ageRestriction) {
        super(supplierId, volume, price, platform);
        this.ageRestriction = ageRestriction;
    }

    protected Minecraft(){
        super();
        ageRestriction = 0;
    }

    boolean equals(Minecraft minecraft){
        return this.ageRestriction == minecraft.ageRestriction;
    }

    @Override
    public void updateProduct(int id,String change,String minecraftInfo) {
        super.updateProduct(id, change, minecraftInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("age restriction")) {
            this.setAgeRestriction(Integer.parseInt(minecraftInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getAgeRestriction() {
        return ageRestriction;
    }

    public void setAgeRestriction(int ageRestriction){
        this.ageRestriction = ageRestriction;
    }

    @Override
    public String display_product_info() {
        return "Minecraft{" +
                "ageRestriction='" + ageRestriction + '\'' +
                ", platform='" + getPlatform() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this)+
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