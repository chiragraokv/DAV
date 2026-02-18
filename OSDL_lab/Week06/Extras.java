//Write a java program to find the occurrence of  word in a given file
package Week06;
import java.io.*;
public class Extras{
    public static int occurrence(String filename, String word)
    {
        int count = 0;
        try{
            BufferedReader br = new BufferedReader(new FileReader(filename));
            String line;
            while ((line = br.readLine()) != null) {
                String[] words = line.split("\\W+"); 
                for (String w : words) {
                    if (w.equalsIgnoreCase(word)) {
                        count++;
                    }
                }
            }
        
        }catch(IOException e){
            System.err.println(e);
        }
        return count;
    }
    public static void main( String[] args){
        //implement all the extra problems
        int i = occurrence("Week06\\notes.txt","the");
        System.out.println(i);;
    }

    
}