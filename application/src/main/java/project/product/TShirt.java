package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class TShirt extends Clothing{
    private String color;

    public TShirt(Supplier supplierId, int volume, double price, String size, String color) {
        super(supplierId, volume, price, size);
        this.color = color;
    }

    protected TShirt() {
        super();
        color = null;
    }

    boolean equals(TShirt tShirt){
        return this.color.equals(tShirt.color);
    }

    @Override
    public void updateProduct(int id,String change,String tShirtInfo) {
        super.updateProduct(id, change, tShirtInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("color")) {
            this.setColor(tShirtInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color){
        this.color = color;
    }

    @Override
    public String display_product_info() {
        return "TShirt{" +
                "color='" + color + '\'' +
                ", size='" + getSize() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
