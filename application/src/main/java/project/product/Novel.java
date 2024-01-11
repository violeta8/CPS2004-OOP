package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Novel extends Book{
    private String genre;

    public Novel(Supplier supplierId, int volume, double price, String title, String genre) {
        super(supplierId, volume, price, title);
        this.genre = genre;
    }


    protected Novel() {
        super();
        genre = null;
    }

    boolean equals(Novel novel){
        return this.genre.equals(novel.genre);
    }

    @Override 
    public void updateProduct(int id,String change,String novelInfo) {
        super.updateProduct(id, change, novelInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("genre")) {
            this.setGenre(novelInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre){
        this.genre = genre;
    }

    @Override
    public String display_product_info() {
        return "Novel{" +
                "genre='" + genre + '\'' +
                ", title='" + getTitle() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
