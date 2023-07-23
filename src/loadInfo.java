import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Arrays;
/** Represents functions for loading data into hashsets and arrays
 * @author Jarrett Fontenot
*/
public class loadInfo {
/**
 * 
 *
 * @param readWords - A hashset that reads all the words from the positive and negative file
 * @throws - throws an exception if no file can be found
 */

    public HashSet<String> readWords(String file1) throws FileNotFoundException {

        HashSet<String> words = new HashSet<String>();
        File file = new File (file1);
        Scanner scnr = new Scanner(file);
        String lines = scnr.nextLine();

        while(scnr.hasNextLine()) {

            if (!lines.startsWith( ";")) {

                String[] lineArray = lines.split("\\s+");

                for(int i = 0; i < lineArray.length; i++) {
                    words.add(lineArray[i]);
                }
            }
            lines = scnr.nextLine();
        }

        scnr.close();
        return words;

}

/**
 * 
 *
 * @param file1 - the name of the directory that holds the text files for the negative or positive words
 *  @throws java.io.IOException when we can't read a file.
 */
    public File[] filesList(String file1) throws IOException {

        File directoryPath = new File(file1);

        File filesList[] = directoryPath.listFiles();
        Arrays.sort(filesList);

        return filesList;
    }
}