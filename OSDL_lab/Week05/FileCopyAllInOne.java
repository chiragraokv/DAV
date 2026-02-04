import java.io.*;

public class FileCopyAllInOne {

    public static void main(String[] args) {

        String sourceFileByte = "sourceByte.dat";
        String destFileByte = "destByte.dat";

        String sourceFileText = "sourceText.txt";
        String destFileText = "destText.txt";

        copyUsingByteStreams(sourceFileByte, destFileByte);

        copyUsingCharacterStreams(sourceFileText, destFileText);
    }

    public static void copyUsingByteStreams(String src, String dest) {
        try (FileInputStream fis = new FileInputStream(src);
             FileOutputStream fos = new FileOutputStream(dest)) {

            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }

            System.out.println("Byte stream copy completed.");

        } catch (IOException e) {
            System.out.println("Error copying byte stream file: " + e.getMessage());
        }
    }

    // Method to copy using FileReader and FileWriter
    public static void copyUsingCharacterStreams(String src, String dest) {
        try (FileReader fr = new FileReader(src);
             FileWriter fw = new FileWriter(dest)) {

            char[] buffer = new char[1024];
            int charsRead;

            while ((charsRead = fr.read(buffer)) != -1) {
                fw.write(buffer, 0, charsRead);
            }

            System.out.println("Character stream copy completed.");

        } catch (IOException e) {
            System.out.println("Error copying character stream file: " + e.getMessage());
        }
    }
}
