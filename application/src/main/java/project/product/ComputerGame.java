package project.product;

import project.supplier.Supplier;

public abstract class ComputerGame extends Product{
    private String platform;

    public ComputerGame(Supplier supplierId, int volume, double price, String platform) {
        super(supplierId, volume, price);
        this.platform = platform;
    }
    
    protected ComputerGame(){
        super();
        platform = null;
    }

    boolean equals(ComputerGame computerGame){
        return this.platform.equals(computerGame.platform);
    }

    @Override
    public void updateProduct(int id,String change,String computerGameInfo) {
        super.updateProduct(id, change, computerGameInfo);
        ProductRepository.deleteProduct(id);
        if(change.equals("platform")) {
            this.setPlatform(computerGameInfo);
        }
        ProductRepository.saveProduct(this);
    }

    public String getPlatform() {
        return platform;
    }

    public void setPlatform(String platform){
        this.platform = platform;
    }

    @Override
    public abstract String display_product_info();
}
