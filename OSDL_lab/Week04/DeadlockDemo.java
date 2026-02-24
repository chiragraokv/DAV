package Week04;

class ResourceA {
    synchronized void methodA(ResourceB b) {
        System.out.println(Thread.currentThread().getName() + " locked ResourceA");

        try { Thread.sleep(100); } catch (InterruptedException e) {}

        System.out.println(Thread.currentThread().getName() + " trying to lock ResourceB");
        b.last();
    }

    synchronized void last() {
        System.out.println("Inside ResourceA last()");
    }
}

class ResourceB {
    synchronized void methodB(ResourceA a) {
        System.out.println(Thread.currentThread().getName() + " locked ResourceB");

        try { Thread.sleep(100); } catch (InterruptedException e) {}

        System.out.println(Thread.currentThread().getName() + " trying to lock ResourceA");
        a.last();
    }

    synchronized void last() {
        System.out.println("Inside ResourceB last()");
    }
}

public class DeadlockDemo implements Runnable {

    ResourceA a = new ResourceA();
    ResourceB b = new ResourceB();

    DeadlockDemo() {
        Thread t1 = new Thread(this, "Thread-1");
        Thread t2 = new Thread(this, "Thread-2");
        t1.start();
        t2.start();
    }

    @Override
    public void run() {
        if (Thread.currentThread().getName().equals("Thread-1")) {
            a.methodA(b);  // locks A → waits for B
        } else {
            b.methodB(a);  // locks B → waits for A
        }
    }

    public static void main(String[] args) {
        new DeadlockDemo();
    }
}

