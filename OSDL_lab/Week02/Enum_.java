package Week02;

enum Books{
    FICTION("Robin",100.00),
    THRILLER("Chirag",123.00),
    SELF_HELP("Kenneth",1234.99);
    
    private String author;
    private double price;
    Books(String auth, double p){
        author = auth;
        price = p;
    }
    public double get_price(){
        return price;
    }
    public String get_name(){
        return author;
    }
}


class Buy{
    private double price;
    private String customer;
    private boolean in_stock;
    private Books B;
    Buy(Books b, boolean in_s){
        in_stock = in_s;
        price = b.get_price();
        B = b;
    }

    public void sell(String c){
        if(in_stock){
        in_stock = false;
        System.out.println(B.get_name()+" Sold to "+c+" at "+ price);
        }
        else{
            System.out.println("Out of stock");
        }
    }
}

public class Enum_ {
    public static void main(String[] args){
        Books b1 = Books.FICTION;
        Books b2 = Books.SELF_HELP;
        Buy b1_ = new Buy(b1,true);
        Buy b2_ = new Buy(b2,true);
        b1_.sell("Chirag");
        b2_.sell("Kenneth");
        

    }

    
}
