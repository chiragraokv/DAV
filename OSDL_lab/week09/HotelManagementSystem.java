import javafx.application.Application;
import javafx.collections.*;
import javafx.geometry.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class HotelManagementSystem extends Application {

    // Data storage
    private ObservableList<Room> rooms = FXCollections.observableArrayList();
    private ObservableList<Room> filteredRooms = FXCollections.observableArrayList();

    private TableView<Room> table = new TableView<>();
 
    @Override
    public void start(Stage stage) {

        // ---------------- ROOM INPUT ----------------
        TextField roomNoField = new TextField();
        TextField priceField = new TextField();

        ComboBox<String> typeBox = new ComboBox<>();
        typeBox.getItems().addAll("Single", "Double", "Deluxe");

        Button addRoomBtn = new Button("Add Room");
        Button showAllBtn = new Button("Show All Rooms");
        Button showAvailableBtn = new Button("Show Available");

        Label message = new Label();

        GridPane roomForm = new GridPane();
        roomForm.setHgap(10);
        roomForm.setVgap(10);

        roomForm.add(new Label("Room No:"), 0, 0);
        roomForm.add(roomNoField, 1, 0);

        roomForm.add(new Label("Type:"), 0, 1);
        roomForm.add(typeBox, 1, 1);

        roomForm.add(new Label("Price:"), 0, 2);
        roomForm.add(priceField, 1, 2);

        roomForm.add(addRoomBtn, 1, 3);

        HBox roomButtons = new HBox(10, showAllBtn, showAvailableBtn);

        // ---------------- TABLE ----------------
        TableColumn<Room, Integer> col1 = new TableColumn<>("Room No");
        col1.setCellValueFactory(new PropertyValueFactory<>("roomNumber"));

        TableColumn<Room, String> col2 = new TableColumn<>("Type");
        col2.setCellValueFactory(new PropertyValueFactory<>("type"));

        TableColumn<Room, Double> col3 = new TableColumn<>("Price");
        col3.setCellValueFactory(new PropertyValueFactory<>("price"));

        TableColumn<Room, Boolean> col4 = new TableColumn<>("Available");
        col4.setCellValueFactory(new PropertyValueFactory<>("available"));

        table.getColumns().addAll(col1, col2, col3, col4);
        table.setItems(rooms);

        // ---------------- CUSTOMER FORM ----------------
        TextField nameField = new TextField();
        TextField contactField = new TextField();
        TextField bookRoomField = new TextField();

        Button bookBtn = new Button("Book Room");
        Button checkoutBtn = new Button("Checkout");

        GridPane customerForm = new GridPane();
        customerForm.setHgap(10);
        customerForm.setVgap(10);

        customerForm.add(new Label("Customer Name:"), 0, 0);
        customerForm.add(nameField, 1, 0);

        customerForm.add(new Label("Contact:"), 0, 1);
        customerForm.add(contactField, 1, 1);

        customerForm.add(new Label("Room No:"), 0, 2);
        customerForm.add(bookRoomField, 1, 2);

        customerForm.add(bookBtn, 1, 3);
        customerForm.add(checkoutBtn, 1, 4);

        // ---------------- ACTIONS ----------------

        // Add Room
        addRoomBtn.setOnAction(e -> {
            try {
                int roomNo = Integer.parseInt(roomNoField.getText());
                double price = Double.parseDouble(priceField.getText());

                rooms.add(new Room(roomNo, typeBox.getValue(), price, true));

                message.setText("Room added successfully!");

                roomNoField.clear();
                priceField.clear();
                typeBox.setValue(null);

            } catch (Exception ex) {
                message.setText("Invalid input!");
            }
        });

        // Show All
        showAllBtn.setOnAction(e -> {
            table.setItems(rooms);
        });

        // Show Available
        showAvailableBtn.setOnAction(e -> {
            filteredRooms.clear();
            for (Room r : rooms) {
                if (r.isAvailable()) {
                    filteredRooms.add(r);
                }
            }
            table.setItems(filteredRooms);
        });

        // Book Room
        bookBtn.setOnAction(e -> {
            try {
                int rno = Integer.parseInt(bookRoomField.getText());

                for (Room r : rooms) {
                    if (r.getRoomNumber() == rno) {
                        if (r.isAvailable()) {
                            r.setAvailable(false);
                            table.refresh();
                            message.setText("Room booked successfully!");
                        } else {
                            message.setText("Room already occupied!");
                        }
                        return;
                    }
                }
                message.setText("Room not found!");

            } catch (Exception ex) {
                message.setText("Invalid input!");
            }
        });

        // Checkout
        checkoutBtn.setOnAction(e -> {
            try {
                int rno = Integer.parseInt(bookRoomField.getText());

                for (Room r : rooms) {
                    if (r.getRoomNumber() == rno) {
                        r.setAvailable(true);
                        table.refresh();
                        message.setText("Checkout successful!");
                        return;
                    }
                }

                message.setText("Room not found!");

            } catch (Exception ex) {
                message.setText("Invalid input!");
            }
        });

        // ---------------- LAYOUT ----------------
        VBox root = new VBox(15,
                roomForm,
                roomButtons,
                table,
                customerForm,
                message
        );

        root.setPadding(new Insets(15));

        stage.setScene(new Scene(root, 650, 600));
        stage.setTitle("Hotel Management System");
        stage.show();
    }

    // ---------------- ROOM CLASS ----------------
    public static class Room {
        private int roomNumber;
        private String type;
        private double price;
        private boolean available;

        public Room(int roomNumber, String type, double price, boolean available) {
            this.roomNumber = roomNumber;
            this.type = type;
            this.price = price;
            this.available = available;
        }

        public int getRoomNumber() { return roomNumber; }
        public String getType() { return type; }
        public double getPrice() { return price; }
        public boolean isAvailable() { return available; }

        public void setAvailable(boolean available) {
            this.available = available;
        }
    }

    public static void main(String[] args) {
        launch();
    }
}