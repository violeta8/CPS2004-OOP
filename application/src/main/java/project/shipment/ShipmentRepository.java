package project.shipment;

import java.util.ArrayList;
import java.util.List;

public class ShipmentRepository {
    private static List<Shipment> repository=new ArrayList<Shipment>();
    private static int nextIdShipment;

    public ShipmentRepository() {
        repository = new ArrayList<>();
        nextIdShipment = 0;
    }

    public static int nextIdShipment() {
        return nextIdShipment++;
    }

    public static void saveShipment(Shipment shipment) {
        repository.add(shipment);
    }

    public static void updateShipment(int id, String change, String newchange) {
        if (!repository.contains(repository.get(id))) {
            throw new IllegalAccessError("Shipment not found");
        }
        Shipment shipment = repository.get(id);
        shipment.updateShipment(change, newchange);
    }

    public static Shipment getShipmentById(int id) {
        return repository.get(id);
    }

    public static String getAllShipments() {
        String result="";
        for (Shipment shipment : repository) {
            result += shipment.toString()+"\n";
        }
        return result;
    }

    public static void deleteShipment(int id) {
        if(!repository.contains(repository.get(id))){
            throw new IllegalAccessError("Shipment not found");
        }
        repository.remove(id);
    }
}
