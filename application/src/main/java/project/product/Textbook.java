package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Textbook extends Book{
    private int edition;

    public Textbook(Supplier supplierId, int volume, double price, String title, int edition) {
        super(supplierId, volume, price, title);
        this.edition = edition;
    }

    protected Textbook() {
        super();
        edition = 0;
    }


    boolean equals(Textbook textbook){
        return this.edition == textbook.edition;
    }

    @Override   
    public void updateProduct(int id,String change,String textbookInfo) {
        super.updateProduct(id, change, textbookInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("edition")) {
            this.setEdition(Integer.parseInt(textbookInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getEdition() {
        return edition;
    }

    public void setEdition(int edition){
        this.edition = edition;
    }

    @Override
    public String display_product_info() {
        return "Textbook{" +
                "edition='" + edition + '\'' +
                ", title='" + getTitle() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this) +
                ", price=" + getPrice() + 
                '}';
    }
}
