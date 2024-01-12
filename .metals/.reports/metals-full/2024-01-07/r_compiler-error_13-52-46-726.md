file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/CustomerRepository.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 151
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/CustomerRepository.java
text:
```scala
package project.customer;

import java.util.List;
import java.util.Map;

public interface CustomerRepository {
    public static List<Customer> g@@etAllCustomers();
    public static void saveCustomer(Customer customer);
    public static void updateCustomer(int id,String choice, String info);
    public Customer getCustomerById(int id);
    public Customer getCustomerByName(String name);
    public void deleteCustomer(int id);
    public int nextIdCustomer();
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