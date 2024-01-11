package project.product;

import project.supplier.Supplier;

public abstract class Electronic extends Product{
    private String energyConsumption;

    public Electronic(Supplier supplierId, int volume, double price, String energyConsumption) {
        super(supplierId, volume, price);
        this.energyConsumption = energyConsumption;
    }

    protected Electronic() {
        super();
        energyConsumption = "";
    }

    boolean equals(Electronic electronic){
        return this.energyConsumption == electronic.energyConsumption;
    }

    @Override   
    public void updateProduct(int id,String change,String electronicInfo) {
        super.updateProduct(id, change, electronicInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("energyConsumption")) {
            this.setEnergyConsumption(electronicInfo);
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
    public abstract String display_product_info();

}
