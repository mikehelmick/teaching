import java.util.Scanner;

/**
 * Mike Helmick
 * Program to return information about the user's name
 */
public class Lab4 {
 
    public static void main( String[] args ) {
        Scanner keyboard = new Scanner( System.in );
        
        // read in information
        System.out.print("Enter your first name: ");
        String firstName = keyboard.next();
        System.out.print("Enter your last name: ");
        String lastName = keyboard.next();
        
        // print out information about the name
        System.out.println("Your first name contains " + firstName.length() + " characters.");
        char first = firstName.charAt(0);
        char last = firstName.charAt( firstName.length() - 1 );
        System.out.println("The first character is '" + first + "'");
        System.out.println("The last character is '" + last + "'");
  
        System.out.println("Your last name contains " + lastName.length() + " characters.");
        first = lastName.charAt(0);
        last = lastName.charAt( lastName.length() - 1 );
        System.out.println("The first character is '" + first + "'");
        System.out.println("The last character is '" + last + "'");
        
        System.out.println("If we swap the first characters of your name, then your name would be");
        String newFirst = lastName.charAt(0) + firstName.substring(1);
        String newLast = firstName.charAt(0) + lastName.substring(1);
        System.out.println( newFirst + " " + newLast );
        
    }
    
}