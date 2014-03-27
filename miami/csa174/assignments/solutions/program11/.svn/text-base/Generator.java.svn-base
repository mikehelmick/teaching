import java.util.Random;

public class Generator {
	
	public static void main( String[] args ) {
		Random r = new Random();
		
		int booths = 10;
		int votes = 1000;
		
		System.out.println( booths );
		for( int i = 0; i < votes; i++ ) { 
			System.out.print( r.nextInt(booths) ) ;
			System.out.print( " " );
			if ( r.nextInt(2) == 0 ) {
				System.out.print( "yes" );
			} else {
				System.out.print( "no" );
			}
			System.out.println("");
		}
		System.out.println("-1");
	}
	
}