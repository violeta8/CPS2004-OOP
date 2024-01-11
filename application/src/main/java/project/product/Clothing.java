package project.product;

import project.supplier.Supplier;

public abstract class Clothing extends Product{
    private String size;

    public Clothing(Supplier supplierId, int volume, double price, String size) {
        super(supplierId, volume, price);
        this.size = size;
    }

    protected Clothing() {
        super();
        size = "";
    }

    boolean equals(Clothing clothing){
        return this.size == clothing.size;
    }

    @Override
    public void updateProduct(int id,String change,String clothingInfo) {
        super.updateProduct(id, change, clothingInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("size")) {
            this.setSize(clothingInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size){
        this.size = size;
    }

    @Override
    public abstract String display_product_info();
}
