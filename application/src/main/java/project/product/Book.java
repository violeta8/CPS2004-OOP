package project.product;

import project.supplier.Supplier;

public abstract class Book extends Product{
    private String title;

    public Book(Supplier supplierId, int volume, double price, String title) {
        super(supplierId, volume, price);
        this.title = title;
    }

    protected Book() {
        super();
        title = null;
    }

    boolean equals(Book book){
        return this.title.equals(book.title);
    }

    @Override
    public void updateProduct(int id,String change,String bookInfo) {
        super.updateProduct(id, change, bookInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("price")) {
            this.setPrice(Double.parseDouble(bookInfo));
        }
        if(change.equals("title")) {
            this.setTitle(bookInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title){
        this.title = title;
    }

    @Override
    public abstract String display_product_info();
}
