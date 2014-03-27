import java.util.Scanner;


public class Lab09Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		
		System.out.println("How many temps? ");
		final int amount = kb.nextInt();
		
		for( int i = 0; i < amount; i++ ) {
			System.out.println("Temperature and scale?");
			final double temp = kb.nextDouble();
			final char scale = kb.next().charAt(0);
			
			Temperature tempObj = new Temperature( temp, scale );
			
			System.out.println("-------#" + (i+1) + "--------");
			System.out.printf(" As Fahrenheit: %.5f%n", tempObj.asFahrenheit() );
			System.out.printf(" As Celsius: %.5f%n", tempObj.asCelsius() );
			System.out.printf(" Getters: %.5f %c%n", tempObj.getTemperature(), tempObj.getScale() );
			System.out.println(" toString: " + tempObj );
			
		}
		
	}

}
