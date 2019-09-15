public class dogClass {

    String bark;
    String color;
    double weight;
    private int fetchCounter = 0;
    String[] fetchedItem = {"bone", "toy", "bag"};

    public dogClass(String zbark, String zcolor, double zweight){
        this.bark   = zbark;
        this.color  = zcolor;
        this.weight = zweight;
    }

    public void barkPlease(){
        System.out.println(" Please bark." + bark);
    }

   public void fetch(){
        this.fetchCounter = (this.fetchCounter+1)%3;
        String item = this.fetchedItem[this.fetchCounter];
        System.out.println(" Dog brought:" + item);
   }
}
