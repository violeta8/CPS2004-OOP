package project.shipment;
import java.time.LocalDate;

public abstract class ShipmentDecorator {
    private Shipment wrapee;

    ShipmentDecorator(Shipment wrapee) {
        this.wrapee = wrapee;
    }

    public double getTotalCost() {
        return wrapee.getTotalCost();
    }

    public LocalDate getDeliveryDate() {
        return wrapee.getDeliveryDate();
    }
}
