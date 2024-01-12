package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Tablet extends Electronic{
    private String brand;

    public Tablet(Supplier supplierId, int volume, double price, String energyConsumption, String brand) {
        super(supplierId, volume, price, energyConsumption);
        this.brand = brand;
    }

    protected Tablet() {
        super();
        brand = null;
    }

    boolean equals(Tablet tablet){
        return this.brand.equals(tablet.brand);
    }

    @Override
    public void updateProduct(int id,String change,String tabletInfo) {
        super.updateProduct(id, change, tabletInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("brand")) {
            this.setBrand(tabletInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand){
        this.brand = brand;
    }

    @Override
    public String display_product_info() {
        return "Tablet{" +
                "brand='" + brand + '\'' +
                ", energyConsumption='" + getEnergyConsumption() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
