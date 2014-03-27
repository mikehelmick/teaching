import java.util.Random;


public class BluthCompany {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Random random = new Random();
		
		BananaStand stand1 = new BananaStand( 4 );
		BananaStand stand2 = new BananaStand( 7 );
		BananaStand stand3 = new BananaStand( 1 );
		
		for( int i = 0; i < 60; i++ ) {
			if ( random.nextInt(8) == 0 ) {
				stand1.justSold();
			}
			if ( random.nextInt(8) == 0 ) {
				stand2.justSold();
			}
			if ( random.nextInt(8) == 0 ) {
				stand3.justSold();
			}
		}
		
		System.out.println( stand1 );
		System.out.println( stand2 );
		System.out.println( stand3 );
		
		int totalSold = BananaStand.getTotalSold();
		System.out.println( "Total sold = " + totalSold );
		
	}

}
