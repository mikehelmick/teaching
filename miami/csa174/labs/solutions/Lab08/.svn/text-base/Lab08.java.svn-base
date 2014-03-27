import java.util.Scanner;

public class Lab08 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		
		System.out.print("How many dice rolls should I simulate? ");
		int rolls = kb.nextInt();
		
		Die die = new Die();
		for( int i = 0; i < rolls; i++ ) {
			die.roll();
		}
		
		int highestValue = 1;
		int most = die.rollsByValue(1);
		System.out.println("After " + die.totalRolls() + " here are the counts:");
		for( int i = 1; i <= 6; i++ ) {
			System.out.println( " " + i + " was rolled " + die.rollsByValue(i) + " times. " ); 
			
			if ( die.rollsByValue(i) > most ) {
				highestValue = i;
				most = die.rollsByValue(i);
			}
		}
		
		System.out.println( highestValue + " was rolled the most, with " + most + " rolls.");
	}

}
