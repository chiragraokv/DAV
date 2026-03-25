package Week08;

import java.util.*;

class Room {
    int number;
    String type;
    double price;
    boolean available = true;

    Room(int number, String type, double price) {
        this.number = number;
        this.type = type;
        this.price = price;
    }
}

class Customer {
    int id;
    String name, phone;
    int roomNo;

    Customer(int id, String name, String phone, int roomNo) {
        this.id = id;
        this.name = name;
        this.phone = phone;
        this.roomNo = roomNo;
    }
}

public class HotelManagement {
    static ArrayList<Room> rooms = new ArrayList<>();
    static ArrayList<Customer> customers = new ArrayList<>();
    static HashMap<Integer, Customer> bookings = new HashMap<>();
    static Scanner sc = new Scanner(System.in);

    static Room findRoom(int no) {
        for (Room r : rooms) if (r.number == no) return r;
        return null;
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n1.Add Room 2.View Rooms 3.Add Customer 4.Book 5.Checkout 6.View Customers 7.Exit");
            int ch = sc.nextInt();

            try {
                switch (ch) {
                    case 1:
                        System.out.print("Room No Type Price: ");
                        rooms.add(new Room(sc.nextInt(), sc.next(), sc.nextDouble()));
                        break;

                    case 2:
                        Collections.sort(rooms, Comparator.comparingInt(r -> r.number));
                        for (Room r : rooms)
                            if (r.available)
                                System.out.println(r.number + " " + r.type + " " + r.price);
                        break;

                    case 3:
                        System.out.print("ID Name Phone: ");
                        customers.add(new Customer(sc.nextInt(), sc.next(), sc.next(), -1));
                        break;

                    case 4:
                        System.out.print("Customer ID & Room No: ");
                        int id = sc.nextInt(), rn = sc.nextInt();
                        Room r = findRoom(rn);

                        if (r == null || !r.available) {
                            System.out.println("Room not available");
                            break;
                        }

                        for (Customer c : customers) {
                            if (c.id == id) {
                                c.roomNo = rn;
                                r.available = false;
                                bookings.put(rn, c);
                                System.out.println("Booked");
                            }
                        }
                        break;

                    case 5:
                        System.out.print("Room No: ");
                        int roomNo = sc.nextInt();
                        if (bookings.containsKey(roomNo)) {
                            bookings.get(roomNo).roomNo = -1;
                            findRoom(roomNo).available = true;
                            bookings.remove(roomNo);
                            System.out.println("Checked out");
                        }
                        break;

                    case 6:
                        Iterator<Customer> it = customers.iterator();
                        while (it.hasNext()) {
                            Customer c = it.next();
                            System.out.println(c.id + " " + c.name + " Room:" + c.roomNo);
                        }
                        break;

                    case 7:
                        return;
                }
            } catch (Exception e) {
                System.out.println("Invalid input!");
                sc.nextLine();
            }
        }
    }
}