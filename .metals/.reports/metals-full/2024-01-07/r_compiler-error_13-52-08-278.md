file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/CustomerRepositoryMem.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 261
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/CustomerRepositoryMem.java
text:
```scala
package project.customer;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class CustomerRepositoryMem implements CustomerRepository{
    private static List<Customer> repository;
    private s@@int nextIdCustomer;

    public CustomerRepositoryMem() {
        this.repository = new ArrayList<Customer>();
        this.nextIdCustomer = 1;
    }

    @Override
    public int nextIdCustomer() {
        return this.nextIdCustomer++;
    }

    @Override
    public void saveCustomer(Customer customer) {
        repository.add(customer);
    }

    @Override
    public void updateCustomer(int id,String choice, String info) {
        Customer customer = this.repository.get(id);
        Map<String, String> map = new HashMap<>();
        map.put(choice, info);
        customer.updateCustomer(map);
    }

    @Override
    public Customer getCustomerById(int id) {
        return this.repository.get(id);
    }

    @Override
    public Customer getCustomerByName(String name) {
        for (Customer customer : repository) {
            if (customer.getName().equals(name)) {
                return customer;
            }
        }
        return null;
    }

    @Override
    public List<Customer> getAllCustomers() {
        return repository;
    }

    @Override
    public void deleteCustomer(int id) {
        this.repository.remove(id);
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
	scala.meta.internal.pc.completions.CompletionProvider.completions(CompletionProvider.scala:46)
	scala.meta.internal.pc.ScalaPresentationCompiler.complete$$anonfun$1(ScalaPresentationCompiler.scala:136)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator