package project.shipment;
import java.time.LocalDate;

import project.customer.Customer;

public abstract class ShipmentDecorator implements ShipmentComponent{
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

    public void updateShipment(String change, String newchange) {
        updateShipment(change, newchange);
    }

    public int getIdShipment() {
        return getIdShipment();
    }

    public void setIdShipment(int idShipment) {
        setIdShipment(idShipment);
    }

    public boolean equals(Shipment shipment) {
        return equals(shipment);
    }

    public Customer getCustomer() {
        return getCustomer();
    }

    public void setCustomer(Customer customer) {
        setCustomer(customer);
    }

    public void setDeliveryDate(LocalDate deliveryDate) {
        setDeliveryDate(deliveryDate);
    }

    public LocalDate getPurchaseDate() {
        return getPurchaseDate();
    }

    public void setPurchaseDate(LocalDate purchaseDate) {
        setPurchaseDate(purchaseDate);
    }

}
