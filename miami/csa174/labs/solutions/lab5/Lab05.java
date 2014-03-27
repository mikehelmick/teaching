import java.util.Scanner;

public class Lab05 {
 
  public static void main( String[] args ) {
    Scanner keyboard = new Scanner( System.in );
    
    System.out.print("Enter a year: ");
    int year = keyboard.nextInt();
    
    if ( year < 1582 ) {
        System.out.println( year + " is too early for me to tell");
        
    } else {
      boolean leap = (year % 4 == 0 && year % 100 != 0) ||
                     (year % 400 == 0);
      if ( leap ) {
        System.out.println( year + " is a leap year");
      } else {
            System.out.println( year + " is not a leap year");
      }
      
    }
    
  }
  
}