import java.util.Scanner;

public class Switch {
	
	public static void main( String[] args ) {
		Scanner keyboard = new Scanner( System.in );
		
		System.out.println("Enter A, B, or C: ");
		// read from user, convert to char
		char choice = keyboard.next().charAt(0);
		
		switch( choice ) {
			case 'A':
				System.out.println("You picked choice 1");
				break;
			case 'B':
				System.out.println("You picked choice 2");
				break;
			case 'C':
				System.out.println("You picked choice 3");
				break;
			default:
				System.out.println("Invalid choice");
		}
		
	}
	
}