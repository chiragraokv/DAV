package Week07;
import java.io.*;
class Room<T, U> {
    private T roomIdentifier;
    private U roomValue; // Can be Type or Price

    public Room(T roomIdentifier, U roomValue) {
        this.roomIdentifier = roomIdentifier;
        this.roomValue = roomValue;
    }

    @Override
    public String toString() {
        return "Room [ID: " + roomIdentifier + ", Info: " + roomValue + "]";
    }
}

public class HotelApp {

    public static <V> void displaySystemData(String label, V data) {
        System.out.println(label + ": " + data);
    }

    public static void main(String[] args) {
        System.out.println("=== Hotel Management System Initialized ===\n");
        Room<Integer, String> standardRoom = new Room<>(101, "Double Bed");

        // 2. Using the Generic Method to display the Room objects
        displaySystemData("Standard Room Entry", standardRoom);
        System.out.println("\n--- Processing Individual Attributes ---");
        displaySystemData("Current Room Count", 50);          // Integer

    }
}