file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Textbook.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 304
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/product/Textbook.java
text:
```scala
package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Textbook extends Book{
    private int edition;

    public Textbook(Supplier supplierId, int volume, double price, String title, int edition) {
        super(supplierId, volume, pric@@e, title);
        this.edition = edition;
    }

    protected Textbook() {
        super();
        edition = 0;
    }


    boolean equals(Textbook textbook){
        return this.edition == textbook.edition;
    }

    @Override   
    public void updateProduct(int id,String change,String textbookInfo) {
        super.updateProduct(id, change, textbookInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("edition")) {
            this.setEdition(Integer.parseInt(textbookInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getEdition() {
        return edition;
    }

    public void setEdition(int edition){
        this.edition = edition;
    }

    @Override
    public String display_product_info() {
        return "Textbook{" +
                "edition='" + edition + '\'' +
                ", title='" + getTitle() + '\'' +
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