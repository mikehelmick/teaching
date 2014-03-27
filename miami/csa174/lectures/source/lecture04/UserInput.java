import java.util.Scanner;

// Mike Helmick
// Demo of user input using the Scanner class

public class UserInput { 
    public static void main( String[] args ) {
     
        // get a scanner that reads from the keyboard
        Scanner keyboard = new Scanner( System.in );
        
        // prompt the user for input
        System.out.println("What is your name?");
        String userName = keyboard.nextLine();
        System.out.println("Hello, " + userName + "!");
        
        // more input, numeric this time
        System.out.println("What is your favorite number? ");
        double number = keyboard.nextDouble();
        System.out.println("Wow - " + number + " is a great favorite number.");
        
    }
}