file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/transport/Transport.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 646
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/transport/Transport.java
text:
```scala
package project.transport;
import java.util.Scanner;

public abstract class Transport {
    private int idTransport;
    private int costPerKM;
    private double speed;

    public abstract int route();//this will be added in the subclasses
    
    public Transport(int idTransport, int costPerKM, double speed) {
        this.idTransport = idTransport;
        this.costPerKM = costPerKM;
        this.speed = speed;
    }

    public void updateTransport(String change) {
        Scanner newinfo = new Scanner(System.in);
        if (change == ("costPerKM")) {
            this.costPerKM = newinfo.nextInt();
            n@@
        }
        else if (change == ("speed")) {
            this.speed = newinfo.nextDouble();
        }
        else {
            System.out.println("Invalid input");
        }
    }

    public int getIdTransport() {
        return idTransport;
    }

    public void setIdTransport(int idTransport) {
        this.idTransport = idTransport;
    }

    public int getCostPerKM() {
        return costPerKM;
    }

    public void setCostPerKM(int costPerKM) {
        this.costPerKM = costPerKM;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(double d) {
        this.speed = d;
    }

    @Override
    public String toString() {
        return "transport [costPerKM=" + costPerKM + ", idTransport=" + idTransport + ", speed=" + speed + "]";
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
	scala.meta.internal.pc.completions.CompletionProvider.completions(CompletionProvider.scala:46)
	scala.meta.internal.pc.ScalaPresentationCompiler.complete$$anonfun$1(ScalaPresentationCompiler.scala:136)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator