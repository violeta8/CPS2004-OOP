package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;
public class Pants extends Clothing{
    private String shop;

    public Pants(Supplier supplierId, int volume, double price, String size, String shop) {
        super(supplierId, volume, price, size);
        this.shop = shop;
    }

    protected Pants() {
        super();
        shop = null;
    }

    boolean equals(Pants pants){
        return this.shop.equals(pants.shop);
    }

    @Override
    public void updateProduct(int id,String change,String pantsInfo) {
        super.updateProduct(id, change, pantsInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("shop")) {
            this.setShop(pantsInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getShop() {
        return shop;
    }

    public void setShop(String shop){
        this.shop = shop;
    }

    @Override
    public String display_product_info() {
        return "Pants{" +
                "shop='" + shop + '\'' +
                ", size='" + getSize() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
