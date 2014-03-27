import java.util.Scanner;

/**
 * Rational number calculator
 */
public class Calculator {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		
		int numerator = 0;
		int denominator = 1;
		RationalNumber number = new RationalNumber( numerator, denominator );
		
		System.out.println("Enter operation: + * c e");
		char operation = kb.next().toLowerCase().charAt(0);
		while( operation != 'e' ) {
			
			if ( operation == 'c' ) {
				number.setDenominator(1);
				number.setNumerator(0);
			} else {
				System.out.println("Enter numerator and denominator:");
				numerator = kb.nextInt();
				denominator = kb.nextInt();
				
				if ( operation == '+' ) {
					number = number.add( new RationalNumber( numerator, denominator ) );
				} else {
					number = number.multiply( new RationalNumber( numerator, denominator ) );
				}
				
			}
			
			System.out.println( number + " = " + number.asDouble() );	
			System.out.println("Enter operation: + * c e");
			operation = kb.next().toLowerCase().charAt(0);
		}
	}

}
