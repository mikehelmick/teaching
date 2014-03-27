import java.util.Scanner;


public class Program9 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		Person person = new Person();
		
		System.out.println("You are at (" + person.getXPos() + "," + person.getYPos() + ")");
		System.out.println("Enter the direction to travel ('exit to quit)");
		String dir = kb.next();
		while ( ! (person.validDirection(dir) || dir.equalsIgnoreCase("exit") ) ) {
			System.out.println("ERROR: valid directions are N,NE,E,SE,S,SW,W,NW.");
			System.out.println("Enter the direction to travel ('exit to quit) ");
			dir = kb.next();
		}
		
		while( ! dir.equalsIgnoreCase("exit") ) {
			System.out.println("Enter the number of steps:");
			int steps = kb.nextInt();
			while( ! person.validSteps(steps) ) {
				System.out.println("ERROR: number of steps must be a positive number.");
				System.out.println("Enter the number of steps:");
				steps = kb.nextInt();
			}
			
			person.move(dir, steps);
			
			for( int i = 0; i < 40; i++ ) {
				System.out.print("-");
			}
			System.out.println("");
			
			System.out.println( person );
			
			System.out.println("Enter the direction to travel ('exit to quit)");
			dir = kb.next().toLowerCase();
			while ( ! (person.validDirection(dir) || dir.equalsIgnoreCase("exit") ) ) {
				System.out.println("ERROR: valid directions are N,NE,E,SE,S,SW,W,NW.");
				System.out.println("Enter the direction to travel ('exit to quit) ");
				dir = kb.next();
			}
		}
		
		System.out.println("Your final location is (" + person.getXPos() + "," + person.getYPos() + ")" );
	}

}
