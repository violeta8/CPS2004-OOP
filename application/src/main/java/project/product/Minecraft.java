package project.product;

import project.stock.StockRepository;
import project.supplier.Supplier;

public class Minecraft extends ComputerGame{
    private int ageRestriction;

    public Minecraft(Supplier supplierId, int volume, double price, String platform, int ageRestriction) {
        super(supplierId, volume, price, platform);
        this.ageRestriction = ageRestriction;
    }

    protected Minecraft(){
        super();
        ageRestriction = 0;
    }

    boolean equals(Minecraft minecraft){
        return this.ageRestriction == minecraft.ageRestriction;
    }

    @Override
    public void updateProduct(int id,String change,String minecraftInfo) {
        super.updateProduct(id, change, minecraftInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("age restriction")) {
            this.setAgeRestriction(Integer.parseInt(minecraftInfo));
        }
        ProductRepository.saveProduct(this);
    }

    public int getAgeRestriction() {
        return ageRestriction;
    }

    public void setAgeRestriction(int ageRestriction){
        this.ageRestriction = ageRestriction;
    }

    @Override
    public String display_product_info() {
        return "Minecraft{" +
                "ageRestriction='" + ageRestriction + '\'' +
                ", platform='" + getPlatform() + '\'' +
                ", supplierId=" + getSupplier().getName() +
                ", productId=" + getProductId() +
                ", stock=" + StockRepository.getStockQuantity(this)+
                ", price=" + getPrice() + 
                '}';
    }

}
