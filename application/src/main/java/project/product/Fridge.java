package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Fridge extends HomeAppliance{
    private String energyConsumption;

    public Fridge(Supplier supplierId, int volume, double price, int warrantyPeriod, String energyConsumption) {
        super( supplierId, volume, price, warrantyPeriod);
        this.energyConsumption = energyConsumption;
    }

    protected Fridge(){
        super();
        energyConsumption = "";
    }

    boolean equals(Fridge fridge){
        return this.energyConsumption == fridge.energyConsumption;
    }

    @Override
    public void updateProduct(int id,String change,String fridgeInfo) {
        super.updateProduct(id, change, fridgeInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("energy consumption")) {
            this.setEnergyConsumption(fridgeInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getEnergyConsumption() {
        return energyConsumption;
    }

    public void setEnergyConsumption(String energyConsumption){
        this.energyConsumption = energyConsumption;
    }

    @Override
    public String display_product_info() {
        return "Fridge{" +
                "energyConsumption='" + energyConsumption + '\'' +
                ", warrantyPeriod='" + getWarrantyPeriod() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" +  StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
