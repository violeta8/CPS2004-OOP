file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Electronic.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 273
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Electronic.java
text:
```scala
package project.product;

import project.supplier.Supplier;

public abstract class Electronic extends Product{
    private String energyConsumption;

    public Electronic(Supplier supplierId, int volume, double price, String energyConsumption) {
        super(supp@@lierId, volume, price);
        this.energyConsumption = energyConsumption;
    }

    protected Electronic() {
        super();
        energyConsumption = "";
    }

    boolean equals(Electronic electronic){
        return this.energyConsumption == electronic.energyConsumption;
    }

    @Override   
    public void updateProduct(int id,String change,String electronicInfo) {
        super.updateProduct(id, change, electronicInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("energyConsumption")) {
            this.setEnergyConsumption(electronicInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getEnergyConsumption() {
        return energyConsumption;
    }

    public void setEnergyConsumption(String energyConsumption){
        this.energyConsumption = energyConsumption;
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