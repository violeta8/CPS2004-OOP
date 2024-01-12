package project.transport.plane;


import project.transport.Transport;
import project.transport.TransportRepository;

public class Plane extends Transport {
    private String name;

    public Plane(int idTransport, int costPerKM, double speed, String name) {
        super(idTransport, costPerKM, speed);
        this.name = name;
    }

    protected Plane() {
        super(0, 0, 0);
        this.name = "";
    }

    public boolean equals(Plane plane) {
        return this.name.equals(plane.name);
    }

    @Override
    public void updateTransport(int id, String info, String newchange) {
        super.updateTransport(id, info, newchange);
        TransportRepository.deleteTransport(id);
        if(info.equals("name")) {
            this.name = newchange;
        }
        TransportRepository.saveTransport(this);
    }

    public String getName() {
        return name;
    }

    public void setName(String plate) {
        this.name = plate;
    }

    @Override
    public int route() {
        return 256;
    }

    @Override
    public String toString() {
        return "Plane [name=" + name + super.toString() + "]";
    }
}
