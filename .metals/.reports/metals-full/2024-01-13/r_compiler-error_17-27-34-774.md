file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Clothing.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 334
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Clothing.java
text:
```scala
package project.product;

import project.supplier.Supplier;

public abstract class Clothing extends Product{
    private String size;

    public Clothing(Supplier supplierId, int volume, double price, String size) {
        super(supplierId, volume, price);
        this.size = size;
    }

    protected Clothing() {
  @@      super();
        size = "";
    }

    boolean equals(Clothing clothing){
        return this.size == clothing.size;
    }

    @Override
    public void updateProduct(int id,String change,String clothingInfo) {
        super.updateProduct(id, change, clothingInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("size")) {
            this.setSize(clothingInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size){
        this.size = size;
    }

    @Override
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
	scala.meta.internal.pc.HoverProvider$.hover(HoverProvider.scala:34)
	scala.meta.internal.pc.ScalaPresentationCompiler.hover$$anonfun$1(ScalaPresentationCompiler.scala:342)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator