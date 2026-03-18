package Week07;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class HotelSystem extends Application {

    static class Room {
        int number; String type; double price; boolean available = true;
        Room(int number, String type, double price) { this.number = number; this.type = type; this.price = price; }
    }

    static class Customer {
        String name, contact; int roomNumber;
        Customer(String name, String contact, int roomNumber) { this.name = name; this.contact = contact; this.roomNumber = roomNumber; }
    }

    static ObservableList<Room> rooms = FXCollections.observableArrayList();
    static ObservableList<Customer> customers = FXCollections.observableArrayList();

    public static void main(String[] args) { launch(args); }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Hotel Management System");
        TabPane tabs = new TabPane();

        tabs.getTabs().addAll(
            new Tab("Rooms", createRoomPane()), 
            new Tab("Customers", createCustomerPane()), 
            new Tab("Booking / Checkout", createBookingPane())
        );
        tabs.getTabs().forEach(t -> t.setClosable(false));

        primaryStage.setScene(new Scene(tabs, 600, 400));
        primaryStage.show();
    }

    private VBox createRoomPane() {
        TextField numF = new TextField(), priceF = new TextField();
        ComboBox<String> typeF = new ComboBox<>(FXCollections.observableArrayList("Single","Double","Deluxe"));
        Button addBtn = new Button("Add Room");
        GridPane form = new GridPane(); form.setVgap(5); form.setHgap(5);
        form.addRow(0,new Label("Number:"),numF);
        form.addRow(1,new Label("Type:"),typeF);
        form.addRow(2,new Label("Price:"),priceF);
        form.add(addBtn,1,3);

        TableView<Room> table = createTable(rooms, "Number","Type","Price","Available");

        addBtn.setOnAction(e -> {
            try {
                rooms.add(new Room(Integer.parseInt(numF.getText()), typeF.getValue(), Double.parseDouble(priceF.getText())));
                numF.clear(); typeF.setValue(null); priceF.clear();
            } catch (Exception ex) { new Alert(Alert.AlertType.ERROR,"Invalid input!").showAndWait(); }
        });

        return new VBox(10, form, table);
    }

    private VBox createCustomerPane() {
        TextField nameF = new TextField(), contactF = new TextField(), roomF = new TextField();
        Button addBtn = new Button("Add Customer");
        GridPane form = new GridPane(); form.setVgap(5); form.setHgap(5);
        form.addRow(0,new Label("Name:"),nameF);
        form.addRow(1,new Label("Contact:"),contactF);
        form.addRow(2,new Label("Room Number:"),roomF);
        form.add(addBtn,1,3);

        TableView<Customer> table = createTable(customers, "Name","Contact","Room");

        addBtn.setOnAction(e -> {
            try {
                int rnum = Integer.parseInt(roomF.getText());
                Room room = rooms.stream().filter(r -> r.number==rnum).findFirst().orElse(null);
                if(room==null){ new Alert(Alert.AlertType.ERROR,"Room not found!").showAndWait(); return; }
                if(!room.available){ new Alert(Alert.AlertType.ERROR,"Room occupied!").showAndWait(); return; }
                customers.add(new Customer(nameF.getText(),contactF.getText(),rnum));
                room.available=false; nameF.clear(); contactF.clear(); roomF.clear();
            } catch (Exception ex){ new Alert(Alert.AlertType.ERROR,"Invalid input!").showAndWait(); }
        });

        return new VBox(10, form, table);
    }

    private VBox createBookingPane() {
        ComboBox<Integer> roomBox = new ComboBox<>(); Button bookBtn = new Button("Book Room"), checkoutBtn = new Button("Checkout Room");
        updateRoomBox(roomBox);
        HBox layout = new HBox(10,new Label("Room:"),roomBox,bookBtn,checkoutBtn);

        bookBtn.setOnAction(e -> changeRoomStatus(roomBox,true));
        checkoutBtn.setOnAction(e -> changeRoomStatus(roomBox,false));

        return new VBox(10, layout);
    }

    private <T> TableView<T> createTable(ObservableList<T> list, String... cols){
        TableView<T> table = new TableView<>(list);
        for(String c : cols){
            TableColumn<T,String> col = new TableColumn<>(c);
            col.setCellValueFactory(d -> {
                Object value = null;
                try { value = d.getValue().getClass().getField(c.toLowerCase()).get(d.getValue()); } catch(Exception ignored){}
                return new javafx.beans.property.SimpleStringProperty(value==null?"":value.toString());
            });
            table.getColumns().add(col);
        }
        return table;
    }

    private void updateRoomBox(ComboBox<Integer> box){
        box.getItems().setAll(rooms.stream().filter(r->r.available).map(r->r.number).toList());
    }

    private void changeRoomStatus(ComboBox<Integer> box, boolean book){
        Integer rnum = box.getValue();
        if(rnum==null){ new Alert(Alert.AlertType.ERROR,"Select a room!").showAndWait(); return; }
        Room r = rooms.stream().filter(room -> room.number==rnum).findFirst().orElse(null);
        if(r!=null && r.available==book){ r.available = !book; updateRoomBox(box); new Alert(Alert.AlertType.INFORMATION,book?"Room booked!":"Room checked out!").showAndWait(); }
        else new Alert(Alert.AlertType.ERROR,book?"Room already occupied!":"Room is not occupied!").showAndWait();
    }
}