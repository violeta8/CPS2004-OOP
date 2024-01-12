package project.transport.truck;

import project.transport.Transport;
import project.transport.TransportRepository;
public class Truck extends Transport{
    private String plate;

    public Truck(int idTransport, int costPerKM, double speed, String plate) {
        super(idTransport, costPerKM, speed);
        this.plate = plate;
    }

    protected Truck() {
        super(0, 0, 0);
        this.plate = "";
    }

    public boolean equals(Truck truck) {
        return plate.equals(truck.plate);
    }

    @Override
    public void updateTransport(int id, String change, String newchange) {
        super.updateTransport(id, change, newchange);
        TransportRepository.deleteTransport(id);
        if(change.equals("plate")) {
            plate = newchange;
        }
        TransportRepository.saveTransport(this);
    }

    public String getPlate() {
        return plate;
    }

    public void setPlate(String plate) {
        this.plate = plate;
    }

    @Override
    public int route() {
        return 64;
    }

    @Override
    public String toString() {
        return "Truck [plate=" + plate + super.toString()+ "]";
    }

}
