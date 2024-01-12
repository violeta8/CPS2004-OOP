package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Milk extends Food{
    private String brand;

    public Milk(Supplier supplierId, int volume, double price, String expirationDate, String brand) {
        super(supplierId, volume, price, expirationDate);
        this.brand = brand;
    }

    protected Milk() {
        super();
        brand = null;
    }

    boolean equals(Milk milk){
        return this.brand.equals(milk.brand);
    }

    @Override
    public void updateProduct(int id,String change,String milkInfo) {
        super.updateProduct(id, change, milkInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("brand")) {
            this.setBrand(milkInfo);
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
        return "Milk{" +
                "brand='" + brand + '\'' +
                ", expirationDate='" + getExpirationDate() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" +  StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
