import java.util.Scanner;


public class Lab10 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner( System.in );
		
		System.out.println("Cents in bag1? ");
		int bag1 = scanner.nextInt();
		System.out.println("Cents in bag2? ");
		int bag2 = scanner.nextInt();
		
		Satchel satchel = new Satchel( bag1, bag2 );
		
		while( satchel.getTotalCents() > 0 ) {
			System.out.println( satchel );
			
			System.out.println("Purchase amount? ");
			int purchase = scanner.nextInt();
			
			if ( satchel.makePurchase(purchase) ) {
				System.out.println("Purchase made!");
			} else {
				System.out.println("Not enough money!");
			}
		}
		
		System.out.println("You're out of money, goodbye.");
	}

}
