package project.transport.ship;

import project.transport.Transport;
import project.transport.TransportRepository;

public class Ship extends Transport{
    private String name;

    public Ship(int idTransport, int costPerKM, double speed, String name) {
        super(idTransport, costPerKM, speed);
        this.name = name;
    }

    protected Ship() {
        super(0, 0, 0);
        this.name = "";
    }

    public boolean equals(Ship ship) {
        return this.name.equals(ship.name);
    }

    @Override
    public void updateTransport(int id,String info, String newchange) {
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

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public int route() {
        return 128;
    }
    
    @Override
    public String toString() {
        return "Ship [name=" + name + super.toString()+ "]";
    }
}
