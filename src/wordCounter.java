import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Arrays;
/** Represents functions for counting positive and negative words .
 * @author Jarrett Fontenot
*/
public class wordCounter {
/**
 * 
 *
 * @param array1 - storing the movie reviews
 * @param neg -  stores the negative words in a hashset
 * @param pos - stores the positive words in a hashset
 * @throws - throws an exception if no file can be found
 */
    public void negReviewWordCounter(File array1[], HashSet<String> neg, HashSet<String> pos) throws FileNotFoundException {

    int posWordCounter = 0;
    int negWordCounter = 0;
    String reviewLabel = "";
    double percentCorrect = 0;
    double percentIncorrect = 0;
    double overallNeg = 0;
    double overallPos = 0;
    int totalReviews = 0;

    for(File file : array1) {

        posWordCounter = 0;
        negWordCounter = 0;

        String fileName = file.getPath();

        Scanner scnr = new Scanner(new FileReader(fileName));

        while (scnr.hasNext()) {

            String input = scnr.next();
            input = input.replaceAll("\\p{Punct}", "").toLowerCase();
            String[] inputArray = input.split("\\s+");

                for(int j = 0; j < inputArray.length; j++) {

                    if (neg.contains(inputArray[j])) { 
                        negWordCounter = negWordCounter + 1;
                    }
                    else if(pos.contains(inputArray[j])) {
                        posWordCounter = posWordCounter + 1;
                    }

                }

            if (negWordCounter >= posWordCounter) {
                reviewLabel = "Negative";
            }
            else {
                reviewLabel = "Positive";
            }


    }

            if(reviewLabel == "Negative") {
                overallNeg = overallNeg + 1;
            }
            else {
                overallPos = overallPos + 1;
            }

            System.out.println(file.getName() + "  Real class: Negative  " + "  Predicted class:  " + reviewLabel);
            System.out.println();
            totalReviews = totalReviews + 1;

}
            percentCorrect = (overallNeg * 100) / totalReviews;
            percentIncorrect = (overallPos * 100) / totalReviews;

            System.out.println("Negative folder  ");
            System.out.println();
            System.out.println("Percent correct  " + percentCorrect);
            System.out.println();
            System.out.println("Percent incorrect  " + percentIncorrect);
}

/**
 * 
 * @param array1 - storing the movie reviews
 * @param neg -  stores the negative words in a hashset
 * @param pos - stores the positive words in a hashset
 * @throws - throws an exception if no file can be found
 */

public void posReviewWordCounter(File array1[], HashSet<String> neg, HashSet<String> pos) throws FileNotFoundException {

        int posWordCounter = 0;
        int negWordCounter = 0;
        String reviewLabel = "";
        double percentCorrect = 0;
        double percentIncorrect = 0;
        double overallNeg = 0;
        double overallPos = 0;
        int totalReviews = 0;
        //System.out.println(neg);
    
        for(File file : array1) {
    
            posWordCounter = 0;
            negWordCounter = 0;

            String fileName = file.getPath();
            Scanner scnr = new Scanner(new FileReader(fileName));
            
            while (scnr.hasNext()) {
                
                String input = scnr.next();
                input = input.replaceAll("\\p{Punct}", "").toLowerCase();
                String[] inputArray = input.split("\\s+");
    
                    for(int j = 0; j < inputArray.length; j++) {
    
                        if (neg.contains(inputArray[j])) { 
                            negWordCounter = negWordCounter + 1;
                        }
                        else if(pos.contains(inputArray[j])) {
                            posWordCounter = posWordCounter + 1;
                        }
                    
                    }
    
                if (negWordCounter >= posWordCounter) {
                    reviewLabel = "Negative";
                }
                else {
                    reviewLabel = "Positive";
                }
            }

}
}
}
