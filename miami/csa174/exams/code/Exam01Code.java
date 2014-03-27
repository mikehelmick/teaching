import java.util.Scanner;
public class Exam01Code {
 
  public static void main( String[] args ) {

    Scanner keyboard = new Scanner( System.in );
 
    /*
    int x = keyboard.nextInt();
    int y = keyboard.nextInt();
    
    if ( x == y ) {
      System.out.println("ALPHA");
    } else {
     
      if ( x % 2 == 0 && y > 10 ) {
        System.out.println("BETA");
        
      } else {
        if ( x < 0 || y < 0 ) {
          System.out.println("GAMMA");
        }
      } 
    }
    System.out.println("PI");
    */
    
    /// pq 2
    System.out.print("Enter 3 integers: ");
    int a = keyboard.nextInt();
    int b = keyboard.nextInt();
    int c = keyboard.nextInt();
    
    if ( (a <= b && a >= c) || (a >= b && a <= c) ) {
      System.out.println( a + " is the median");
    } else {
      if ( (b <= a && b >= c) || (b >= a && b <= c) ) {
        System.out.println( b + " is the median");
      } else {
        System.out.println( c + " is the median");
      }
    }
    
    /// pq 3
    /*
    System.out.print("Enter sentence: ");
    String sentence = keyboard.nextLine();
    System.out.print("Enter extra word to capitalize: ");
    String word = keyboard.next();
    
    sentence = sentence.substring(0,1).toUpperCase() +
               sentence.substring(1).toLowerCase();
    word = word.toLowerCase();
    
    int index = sentence.indexOf( word );
    
    if ( index > 0 ) {
      word = word.substring(0,1).toUpperCase() +
             word.substring(1).toLowerCase();
      sentence = sentence.substring(0,index) + word +
                 sentence.substring( index + word.length() );
    }
    System.out.println( sentence );
    */
    
    
    
  }
  
  
}