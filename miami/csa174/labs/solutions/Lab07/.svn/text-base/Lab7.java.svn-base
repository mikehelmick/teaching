import java.util.Scanner;


public class Lab7 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		
		// even number sum
		System.out.print("Enter an integer: ");
		int number = kb.nextInt();
		while ( number < 2 ) {
			System.out.print("ERROR: enter an integer > 2: " );
			number = kb.nextInt();
		}
		int sum = 0;
		for( int i = 2; i <= number; i += 2 ) {
			sum += i;
		}
		System.out.println("Sum of even numbers from 2 to " + number + " = " + sum );
		
		// word
		System.out.print("Enter any word: ");
		String word = kb.next();
		for( int i = 0; i < word.length(); i++ ) {
			System.out.println( "char " + i + ":" + word.charAt(i) );
		}
	}

}
