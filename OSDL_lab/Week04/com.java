package Week04;

class SharedResource {
    private int data;
    private boolean hasData = false;

    synchronized void produce(int value) {
        while (hasData) {
            try { wait();
                System.out.println("waiting producer"+Thread.currentThread().getName());
             } catch (InterruptedException e) {}
        }
        data = value;
        hasData = true;
        System.out.println("Produced: " + data);
        notify();
    }

    synchronized int consume() {
        while (!hasData) {
            try { wait();
                System.out.println("waiting consumer"+Thread.currentThread().getName());
             } catch (InterruptedException e) {}
        }
        hasData = false;
        System.out.println("Consumed: " + data);
        notify();
        return data;
    }
}

class Producer extends Thread {
    SharedResource sr;

    Producer(SharedResource sr) {
        this.sr = sr;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            sr.produce(i);
        }
    }
}

class Consumer extends Thread {
    SharedResource sr;

    Consumer(SharedResource sr) {
        this.sr = sr;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            sr.consume();
        }
    }
}


public class com {
    public static void main(String[] args) {
        SharedResource sr = new SharedResource();
        new Producer(sr).start();
        new Consumer(sr).start();
    }
    
}
