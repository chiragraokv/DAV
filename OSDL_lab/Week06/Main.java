package Week06;
import java.io.Serializable;
import java.io.*;
import java.util.*;

class Room implements Serializable {
    int no; String type, guest;
    double price; boolean booked;

    Room(int n, String t, double p, boolean b, String g) {
        no=n; type=t; price=p; booked=b; guest=g;
    }

    public String toString() {
        return no+" "+type+" "+price+" "+
               (booked?"Booked":"Available")+" "+
               (guest==null?"-":guest);
    }
}

public class Main {

    static String FILE="rooms.ser";

    static List<Room> load() {
        try(ObjectInputStream o=new ObjectInputStream(new FileInputStream(FILE))){
            return (List<Room>)o.readObject();
        } catch(Exception e){ return new ArrayList<>(); }
    }

    static void save(List<Room> l){
        try(ObjectOutputStream o=new ObjectOutputStream(new FileOutputStream(FILE))){
            o.writeObject(l);
        } catch(Exception e){}
    }

    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        while(true){
            System.out.println("1.Add 2.View 3.Search 4.Update 5.Exit");
            int c=s.nextInt(); s.nextLine();
            List<Room> list=load();

            if(c==1){
                int n=s.nextInt(); s.nextLine();
                String t=s.nextLine();
                double p=s.nextDouble();
                boolean b=s.nextBoolean(); s.nextLine();
                String g=b?s.nextLine():null;
                list.add(new Room(n,t,p,b,g));
                save(list);
            }

            if(c==2)
                for(Room r:list) System.out.println(r);

            if(c==3){
                int n=s.nextInt();
                for(Room r:list) if(r.no==n) System.out.println(r);
            }

            if(c==4){
                int n=s.nextInt();
                boolean b=s.nextBoolean(); s.nextLine();
                String g=b?s.nextLine():null;
                for(Room r:list)
                    if(r.no==n){ r.booked=b; r.guest=g; }
                save(list);
            }

            if(c==5) break;
        }
    }
}
