/**
 * A class to represent a rational number
 * @author Mike Helmick
 */
public class RationalNumber {

	private int numerator = 0;
	private int denominator = 1;
	
	public RationalNumber( int numerator, int denominator ) {
		this.numerator = numerator;
		setDenominator(denominator);
		reduce();
	}

	public int getNumerator() {
		return numerator;
	}

	public void setNumerator(int numerator) {
		this.numerator = numerator;
		reduce();
	}

	public int getDenomenator() {
		return denominator;
	}

	public void setDenominator(int denominator) {
		if ( denominator == 0 ) {
			this.denominator = 1;
		} else {
			this.denominator = denominator;
		}
		reduce();
	}
	
	private void reduce() {
		int smallest = Math.min( numerator, denominator );
		int largest = 1; // both divisible by 1
		for( int i = largest; i <= smallest; i++ ) {
			if ( numerator % i == 0 && denominator % i == 0 ) {
				largest = i;
			}
		}
		// worst case - just dividing both by 1
		numerator = numerator / largest;
		denominator = denominator / largest;
	}
	
	public RationalNumber add( RationalNumber other ) {
		if ( this.denominator == other.denominator ) {
			return new RationalNumber( this.numerator + other.numerator, this.denominator );
		} // else not the same denominator
		
		int lcm = lcm( this.denominator, other.denominator );
		int ma = lcm / this.denominator;
		int mb = lcm / other.denominator;
		
		return new RationalNumber( this.numerator * ma + other.numerator * mb,
								   this.denominator * ma );
	}
	
	public RationalNumber multiply( RationalNumber other ) {
		return new RationalNumber( this.numerator * other.numerator,
								   this.denominator * other.denominator );
	}
	
	public double asDouble() {
		return ((double)numerator)/denominator;
	}
	
	public String toString() {
		return numerator + "/" + denominator;
	}
	
	private static int lcm(int a, int b ) {
		return a * b / gcd(a, b);
	}
	
	private static int gcd(int a, int b) {
		if ( a < b ) {
			return gcd( b, a );
		}
		
		if ( b == 0 ) {
			return a;
		}
		return gcd( b, a % b );
	}
	
}
