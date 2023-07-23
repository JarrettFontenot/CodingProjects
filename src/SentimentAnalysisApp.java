import java.io.File;
//import java.io.FileNotFoundException;
//import java.io.FileReader;
//import java.io.IOException;
import java.util.HashSet;
//import java.util.Scanner;
//import java.util.Arrays;

/** Represents the main method and driver.
 * @author Jarrett Fontenot
*/
public class SentimentAnalysisApp {
/**
 * Our main method. Some kind of handy description goes here.
 * @param args The command line arguments.
 * @throws java.io.IOException when we can't read a file.
 **/
public static void main(String[] args) throws Exception {

    SentimentAnalysisApp app = new SentimentAnalysisApp();
    loadInfo app2 = new loadInfo();
    wordCounter app3 = new wordCounter();
    String negativeFile = args[0];
    String positiveFile = args[1];
    String negReviewFolder = args[2];
    String posReviewFolder = args[3];

    HashSet<String> negativeWords = app2.readWords(negativeFile);
    HashSet<String> positiveWords = app2.readWords(positiveFile);

    File negFilesList[] = app2.filesList(negReviewFolder);
    File posFilesList[] = app2.filesList(posReviewFolder);
    app3.negReviewWordCounter(negFilesList, negativeWords, positiveWords);
    System.out.println();
    System.out.println();
    app3.posReviewWordCounter(posFilesList, negativeWords, positiveWords);

}
}

