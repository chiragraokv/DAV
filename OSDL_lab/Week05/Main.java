import java.io.FileInputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        FileInputStream fis = null;
        try {
            // Open the file
            fis = new FileInputStream("OSDL_lab/Week05/input.txt");
            
            int data;
            System.out.println("File contents:");
            
            // Read file byte by byte
            while ((data = fis.read()) != -1) {
                System.out.print((char) data);
            }
                
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
            e.printStackTrace();
            
        } finally {
            // Always close the stream
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException e) {
                    System.err.println("Error closing file: " + e.getMessage());
                }
            }
        }
    }

}
