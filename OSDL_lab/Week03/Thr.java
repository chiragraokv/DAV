package Week03;

class Parse_book implements Runnable{
    private String title;
    private int pages;
    Parse_book(String t, int p){
        this.pages = p;
        this.title = t;
    }

    @Override
    public void run(){
        for( int i=0;i<pages;i++){
            System.out.println("Parsing Book "+ title+" at :"+i +"/"+pages);
            System.out.println(Thread.currentThread().getName()+ " Priority"+Thread.currentThread().getPriority());
            try{
                System.out.println("sleep");
                Thread.sleep(100);

            }catch (InterruptedException e){
                System.out.println(title+" got interrupted"+e);
            }
        }
    }
}

class Library{
    private String[] title;
    Library(){
        title = new String[3];
        title[0] = "this is a title";
        title[1] = "Fan";
        title[2] = "scooter";
        available = false;
    }
    private boolean available = true;

    synchronized String access(int index)
    {
        while(!available){
            try{
                wait();
            }catch(InterruptedException e){}
        }
        available = true;
        System.out.println("accessed by "+Thread.currentThread().getName());
        notify();
        return title[index];
        
    }
}

public class Thr {
    public static void main(String[] args) {
        Library l = new Library();

        Thread B1 = new Thread( new Parse_book(l.access(0), 10));
        Thread B2 = new Thread(new Parse_book(l.access(2), 10));
        B1.start();   // starts first thread
        B2.start();   // starts second thread
    }
}
