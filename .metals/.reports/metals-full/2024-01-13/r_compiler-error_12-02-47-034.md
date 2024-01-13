file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/ComputerGame.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/ComputerGame.java
text:
```scala
package project.product;

import project.supplier.Supplier;

public abstract class ComputerGame extends Product{
    private String platform;

    public ComputerGame(Supplier supplierId, int volume, double price, String platform) {
        super(supplierId, volume, price);
        this.platform = platform;
    }
    
    protected ComputerGame(){
        super();
        platform = null;
    }

    boolean equals(ComputerGame computerGame){
        return this.platform.equals(computerGame.platform);
    }

    @Override
    public void updateProduct(int id,String change,String computerGameInfo) {
        super.updateProduct(id, change, computerGameInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("platform")) {
            this.setPlatform(computerGameInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getPlatform() {
        return platform;
    }

    public void setPlatform(String platform){
        this.platform = platform;
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
	scala.meta.internal.pc.PcSyntheticDecorationsProvider.<init>(PcSyntheticDecorationProvider.scala:37)
	scala.meta.internal.pc.ScalaPresentationCompiler.syntheticDecorations$$anonfun$1(ScalaPresentationCompiler.scala:110)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator