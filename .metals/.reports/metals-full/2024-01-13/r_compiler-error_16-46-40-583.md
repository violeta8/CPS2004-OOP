file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/customer/CustomerRepository.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 943
uri: file:///C:/Users/viole/Desktop/ERASMUS/cps2004-oop-1/application/src/main/java/project/customer/CustomerRepository.java
text:
```scala
package project.customer;

import java.util.List;
import java.util.ArrayList;

public class CustomerRepository {
    private static List<Customer> repository=new ArrayList<Customer>();
    private static int nextIdCustomer=0;

    public CustomerRepository() {
        repository = new ArrayList<Customer>();
        nextIdCustomer = 0;
    }

    public static int nextIdCustomer() {
        return nextIdCustomer++;
    }

    public static void saveCustomer(Customer customer) {
        repository.add(customer);
    }

    public static void updateCustomer(int id,String change,String newchange) {
        if (!repository.contains(repository.get(id))) {
            throw new IllegalAccessError ("Customer not found");
        }
        Customer customer = repository.get(id);
        customer.updateCustomer(change,newchange);
    }

    public static Customer getCustomerById(int id) {
        return repos@@itory.get(id);
    }

    public static Customer getCustomerByName(String name) {
        for (Customer customer : repository) {
            if (customer.getName().equals(name)) {
                return customer;
            }
        }
        return null;
    }

    public static String getAllCustomers() {
        String result="";
        for (Customer customer : repository) {
            result += customer.toString()+"\n";
            
        }
        return result;
    }

    public static void deleteCustomer(Customer customer) {
        repository.remove(customer);
    }
    //todo get this fixed
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