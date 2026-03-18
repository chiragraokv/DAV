package Week06;
import java.io.*; 
import java.util.Scanner;

public class Hm  {

    static final int TYPE_LENGTH = 20;
    static final int RECORD_SIZE = 4 + (2 * TYPE_LENGTH) + 8 + 1;

    // Add Room
    public static void addRoom(int roomNo, String type, double price, boolean status) {
        try {
            RandomAccessFile raf = new RandomAccessFile("hotel.dat", "rw");
            long position = (roomNo - 1) * RECORD_SIZE;
            raf.seek(position);
            raf.writeInt(roomNo);
            StringBuffer sb = new StringBuffer(type);
            sb.setLength(TYPE_LENGTH);
            raf.writeChars(sb.toString());
            raf.writeDouble(price);
            raf.writeBoolean(status);
            raf.close();
            System.out.println("Room added successfully.");

        } catch (IOException e) {
            System.out.println(e);
        }
    }

    // Display Room
    public static void displayRoom(int roomNo) {
        try {
            RandomAccessFile raf = new RandomAccessFile("hotel.dat", "r");

            long position = (roomNo - 1) * RECORD_SIZE;
            raf.seek(position);

            int rNo = raf.readInt();

            char[] typeChars = new char[TYPE_LENGTH];
            for (int i = 0; i < TYPE_LENGTH; i++)
                typeChars[i] = raf.readChar();

            String type = new String(typeChars).trim();

            double price = raf.readDouble();
            boolean status = raf.readBoolean();

            System.out.println("Room Number: " + rNo);
            System.out.println("Room Type: " + type);
            System.out.println("Price per Night: " + price);
            System.out.println("Booking Status: " + (status ? "Booked" : "Available"));

            raf.close();

        } catch (IOException e) {
            System.out.println("Room not found.");
        }
    }

    // Update Booking Status
    public static void updateStatus(int roomNo, boolean newStatus) {
        try {
            RandomAccessFile raf = new RandomAccessFile("hotel.dat", "rw");

            long position = (roomNo - 1) * RECORD_SIZE;

            // Move to booking status position
            position += 4 + (2 * TYPE_LENGTH) + 8;

            raf.seek(position);
            raf.writeBoolean(newStatus);

            raf.close();
            System.out.println("Booking status updated.");

        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. Add Room");
            System.out.println("2. Display Room");
            System.out.println("3. Update Booking Status");
            System.out.println("4. Exit");
            System.out.print("Choose option: ");

            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter Room Number: ");
                    int rNo = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Enter Room Type: ");
                    String type = sc.nextLine();
                    System.out.print("Enter Price per Night: ");
                    double price = sc.nextDouble();
                    System.out.print("Is Booked? (true/false): ");
                    boolean status = sc.nextBoolean();
                    addRoom(rNo, type, price, status);
                    break;
                case 2:
                    System.out.print("Enter Room Number to Display: ");
                    displayRoom(sc.nextInt());
                    break;
                case 3:
                    System.out.print("Enter Room Number: ");
                    int room = sc.nextInt();
                    System.out.print("Enter New Status (true=Booked / false=Available): ");
                    boolean newStatus = sc.nextBoolean();
                    updateStatus(room, newStatus);
                    break;                                                                           
                case 4:
                    sc.close();                     
                    System.exit(0);
            }
        }
    }
}
