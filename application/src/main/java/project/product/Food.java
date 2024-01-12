package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public abstract class Food extends Product{
    private String expirationDate;

    public Food(Supplier supplierId, int volume, double price, String expirationDate) {
        super(supplierId, volume, price);
        this.expirationDate = expirationDate;
    }

    protected Food() {
        super();
        expirationDate = null;
    }

    boolean equals(Food food){
        return this.expirationDate.equals(food.expirationDate);
    }

    @Override
    public void updateProduct(int id,String change,String foodInfo) {
        super.updateProduct(id, change, foodInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("expirationDate")) {
            this.setExpirationDate(foodInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getExpirationDate() {
        return expirationDate;
    }

    public void setExpirationDate(String expirationDate){
        this.expirationDate = expirationDate;
    }

    @Override
    public String display_product_info() {
        return "Food{" +
                "expirationDate='" + expirationDate + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
