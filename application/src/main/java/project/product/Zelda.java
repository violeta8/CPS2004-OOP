package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Zelda extends ComputerGame{
    private String rating;

    public Zelda(Supplier supplierId, int volume, double price, String platform, String rating) {
        super(supplierId, volume, price, platform);
        this.rating = rating;
    }

    protected Zelda(){
        super();
        rating = "";
    }

    boolean equals(Zelda zelda){
        return this.rating == zelda.rating;
    }

    @Override
    public void updateProduct(int id,String change,String zeldaInfo) {
        super.updateProduct(id, change, zeldaInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("rating")) {
            this.setRating(zeldaInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getRating() {
        return rating;
    }

    public void setRating(String rating){
        this.rating = rating;
    }

    @Override
    public String display_product_info() {
        return "Zelda{" +
                "rating='" + rating + '\'' +
                ", platform='" + getPlatform() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
