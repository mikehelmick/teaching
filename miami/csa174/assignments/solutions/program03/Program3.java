import java.util.Scanner;

// Mike Helmick
// Instructor: Dr. Mike Helmick
// program to convert time to seconds, and return minimum dollar representation
public class Program3 {
 
    public static void main( String[] args ) {
        Scanner kb = new Scanner( System.in );
        
        
        // PP 2.6 part, read in time
        System.out.print("Enter the number of hours: ");
        int hours = kb.nextInt();
        System.out.print("Enter the number of minutes: ");
        int minutes = kb.nextInt();
        System.out.print("Enter the number of seconds: ");
        int seconds = kb.nextInt();
        
        int totalSeconds = hours * 60 * 60 + minutes * 60 + seconds;
        System.out.println("Total seconds = " + totalSeconds );
        
        
        // PP 2.9 part, read in money
        System.out.print("Enter the amount of money you have: ");
        double moneyDouble = kb.nextDouble();
        
        // multiple by 100, so that we don't have to deal with centabos
        int money = (int) (moneyDouble * 100);
        
        // bills - 10, 5, 1
        final int tens = money / 1000;
        money %= 1000;
        final int fives = money / 500;
        money %= 500;
        final int ones = money / 100;
        money %= 100;
        
        // coins 25, 10, 5, 1
        final int quarters = money / 25;
        money %= 25;
        final int dimes = money / 10;
        money %= 10;
        final int nickels = money / 5;
        money %= 5;
        final int pennies = money;
        
        System.out.println( tens + " ten dollar bills");
        System.out.println( fives + " five dollar bills");
        System.out.println( ones + " one dollar bills");
        System.out.println( quarters + " quarters");
        System.out.println( dimes + " dimes");
        System.out.println( nickels + " nickels");
        System.out.println( pennies + " pennies");
        
        
    }
    
}