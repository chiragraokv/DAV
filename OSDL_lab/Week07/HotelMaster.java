package Week07;
class Pair<T, U> {
    T id; U guest;
    Pair(T i, U g) { id = i; guest = g; }
    void show() { System.out.println("Room " + id + ": " + guest); }
}

public class HotelMaster {
    static <T extends Number> void calc(T price, T disc) {
        double total = price.doubleValue() - disc.doubleValue();
        System.out.println("Final Price: " + total);
    }

    static <T> void printArr(T[] arr) {
        for (T item : arr) System.out.print(item + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        // Test Calculations & Arrays
        calc(200.0, 25.5); 
        printArr(new Integer[]{101, 102, 103});
        printArr(new String[]{"Suite", "Basic"});

        // Test Booking Pair
        new Pair<>(505, "Alex").show();
    }
}