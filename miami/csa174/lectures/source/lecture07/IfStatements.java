import java.util.Scanner;

/**
 * @author Mike Helmick
 * A simple program to demonstrate if statements
 */
public class IfStatements {
 
    public static void main (String[] args ) {
        Scanner keyboard = new Scanner( System.in );
        
        // determine even/odd
        System.out.print("Please enter an integer number: " );
        int number = keyboard.nextInt();
        
        if ( number == 0 ) {
            System.out.println("0 is neither even nor odd.");
        } else {       
            if ( number % 2 == 0 ) {
                System.out.println( number + " is even.");
            } else {
                System.out.println( number + " is odd.");
            }
        }
        
  
        
    }
    
}