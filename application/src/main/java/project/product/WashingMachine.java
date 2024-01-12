package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class WashingMachine extends HomeAppliance {
    private int capacity;

    public WashingMachine(Supplier supplierId, int volume, double price, int warrantyPeriod, int capacity) {
        super(supplierId, volume, price, warrantyPeriod);
        this.capacity = capacity;
    }

    protected WashingMachine(){
        super();
        capacity = 0;
    }

    boolean equals(WashingMachine washingMachine){
        return this.capacity == washingMachine.capacity;
    }

    @Override
    public void updateProduct(int id,String change,String washingMachineInfo) {
        super.updateProduct(id, change, washingMachineInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("capacity")) {
            this.setCapacity(Integer.parseInt(washingMachineInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity){
        this.capacity = capacity;
    }

    @Override
    public String display_product_info() {
        return "WashingMachine{" +
                "capacity='" + capacity + '\'' +
                ", warrantyPeriod='" + getWarrantyPeriod() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
