package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Cheese extends Food {
    private int fatContent;

    public Cheese(Supplier supplierId, int volume, double price, String expirationDate, int fatContent) {
        super(supplierId, volume, price, expirationDate);
        this.fatContent = fatContent;
    }

    protected Cheese() {
        super();
        fatContent = 0;
    }

    boolean equals(Cheese cheese){
        return this.fatContent == cheese.fatContent;
    }

    @Override
    public void updateProduct(int id,String change,String cheeseInfo) {
        super.updateProduct(id, change, cheeseInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("fat content")) {
            this.setFatContent(Integer.parseInt(cheeseInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getFatContent() {
        return fatContent;
    }

    public void setFatContent(int fatContent){
        this.fatContent = fatContent;
    }

    @Override
    public String display_product_info() {
        return "Cheese{" +
                "fatContent='" + fatContent + '\'' +
                ", expirationDate='" + getExpirationDate() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" +  StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
