import java.util.Scanner;
public class E2L {
  
  public static void main( String[] args ) {
    Scanner kb = new Scanner( System.in );

    // YOU DON'T NEED TO INCLUDE THE NEXT LINE AS OUTPUT
	System.out.println("Enter 2 ints:");
    int x = kb.nextInt();
    int y = kb.nextInt();

    do {
      System.out.println("loop one.");
    } while( x == y );
	
    while( x >= 0 ) {
      System.out.println( "\nx=" + x );
      for( int i = x; i >= (x - y); i-- ) {
	    int res = x - i;
	    System.out.print( " " + res );
      }
      x--;
	  y++;
    }
  }

}
