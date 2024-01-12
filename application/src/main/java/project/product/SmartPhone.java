package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class SmartPhone extends Electronic{
    private String OS;

    public SmartPhone(Supplier supplierId, int volume, double price, String energyConsumption, String OS) {
        super(supplierId, volume, price, energyConsumption);
        this.OS = OS;
    }

    protected SmartPhone() {
        super();
        OS = null;
    }

    boolean equals(SmartPhone smartPhone){
        return this.OS.equals(smartPhone.OS);
    }

    @Override
    public void updateProduct(int id,String change,String smartPhoneInfo) {
        super.updateProduct(id, change, smartPhoneInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("os")) {
            this.setOS(smartPhoneInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getOS() {
        return OS;
    }

    public void setOS(String OS){
        this.OS = OS;
    }

    @Override
    public String display_product_info() {
        return "SmartPhone{" +
                "OS='" + OS + '\'' +
                ", energyConsumption='" + getEnergyConsumption() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
