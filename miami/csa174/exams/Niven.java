
public final class Niven {

	public static boolean isNiven( int i ) {
		int digitSum = 0;
		
		int number = i;
		while( number >= 10 ) {
			digitSum += number % 10;
			number /= 10;
		}
		digitSum += number;
		
		return i % digitSum == 0;
	}

	public static void main( String[] args ) {
		int i = Integer.parseInt( args[0] );
		for( int j = 1; j <= i; j++ ) {
			System.out.printf("%5d -> %s%n", j, isNiven(j)+"" );
		}
	}
	

}
