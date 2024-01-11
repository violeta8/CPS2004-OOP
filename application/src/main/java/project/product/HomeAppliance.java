package project.product;

import project.supplier.Supplier;

public abstract class HomeAppliance extends Product{
    private int warrantyPeriod;

    public HomeAppliance(Supplier supplierId, int volume, double price, int warrantyPeriod) {
        super(supplierId, volume, price);
        this.warrantyPeriod = warrantyPeriod;
    }

    protected HomeAppliance(){
        super();
        warrantyPeriod = 0;
    }

    boolean equals(HomeAppliance homeAppliance){
        return this.warrantyPeriod == homeAppliance.warrantyPeriod;
    }

    @Override
    public void updateProduct(int id,String change,String homeApplianceInfo) {
        super.updateProduct(id, change, homeApplianceInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("warranty")) {
            this.setWarrantyPeriod(Integer.parseInt(homeApplianceInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getWarrantyPeriod() {
        return warrantyPeriod;
    }

    public void setWarrantyPeriod(int warrantyPeriod){
        this.warrantyPeriod = warrantyPeriod;
    }

    @Override
    public abstract String display_product_info();
}
