public class Dice {
	public static void main( String[] args ) {
	
		Die die1 = new Die();
		Die die2 = new Die();
		
		int rolls = 1;
		die1.roll();
		die2.roll();
		while( die1.getFaceValue() != die2.getFaceValue() ) {
			die1.roll();
			die2.roll();
			rolls++;	
		}
		
		System.out.println("After " + rolls + " rolls - the dice are the same.");
		System.out.println("Die 1: " + die1 );
		System.out.println("Die 2: " + die2 );
	}
}

