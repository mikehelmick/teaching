import java.util.Scanner;


public class Program8 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		
		// some constants
		final double NE = Math.PI / 4.0;
		final double SE = NE + Math.PI / 2.0;
		final double SW = SE + Math.PI / 2.0;
		final double NW = SW + Math.PI / 2.0;
		
		int x = 0;
		int y = 0;
		int totalSteps = 0;
		
		System.out.println("You are at (" + x + "," + y + ")");
		System.out.println("Enter the direction to travel ('exit to quit)");
		String dir = kb.next().toLowerCase();
		while ( ! (dir.equals("n")||dir.equals("s")||dir.equals("e")||dir.equals("w")||
				   dir.equals("ne")||dir.equals("nw")||dir.equals("se")||dir.equals("sw")||
				   dir.equals("exit") ) ) {
			System.out.println("ERROR: valid directions are N,NE,E,SE,S,SW,W,NW.");
			System.out.println("Enter the direction to travel ('exit to quit) ");
			dir = kb.next().toLowerCase();
		}
		
		int steps = -1;
		while( ! dir.equals("exit") ) {
			System.out.println("Enter the number of steps:");
			steps = kb.nextInt();
			while( steps <= 0 ) {
				System.out.println("ERROR: number of steps must be a positive number.");
				System.out.println("Enter the number of steps:");
				steps = kb.nextInt();
			}
			totalSteps += steps;
			
			if ( dir.equals("n") ) {
				y += steps;
			} else if ( dir.equals("s") ) {
				y -= steps;
			} else if ( dir.equals("e") ) {
				x += steps;
			} else if ( dir.equals("w") ) {
				x -= steps;
			} else if ( dir.equals("ne") ) {
				int xc = (int) Math.ceil( steps * Math.sin( NE ) );
				int yc = (int) Math.ceil( steps * Math.cos( NE ) );
				x += xc;
				y += yc;
				
			} else if ( dir.equals("nw") ) {
				int xc = (int) Math.ceil( steps * Math.sin( NW ) );
				int yc = (int) Math.ceil( steps * Math.cos( NW ) );
				x += xc;
				y += yc;
				
			} else if ( dir.equals("se") ) {
				int xc = (int) Math.ceil( steps * Math.sin( SE ) );
				int yc = (int) Math.ceil( steps * Math.cos( SE ) );
				x += xc;
				y += yc;
				
			} else if ( dir.equals("sw") ) {
				int xc = (int) Math.ceil( steps * Math.sin( SW) );
				int yc = (int) Math.ceil( steps * Math.cos( SW ) );
				x += xc;
				y += yc;
				
			}
			
			for( int i = 0; i < 40; i++ ) {
				System.out.print("-");
			}
			System.out.println("");
			
			
			System.out.println("You are now at (" + x + "," + y + ")");
			System.out.print("Steps Taken (" + totalSteps + "): ");
			int intervals = (int) Math.ceil( totalSteps / 10.0 );
			for( int i = 0; i < intervals; i++ ) {
				System.out.print("*");
			}
			System.out.println("");
			System.out.println("Enter the direction to travel ('exit to quit)");
			dir = kb.next().toLowerCase();
			while ( ! (dir.equals("n")||dir.equals("s")||dir.equals("e")||dir.equals("w")||
					   dir.equals("ne")||dir.equals("nw")||dir.equals("se")||dir.equals("sw")||
					   dir.equals("exit") ) ) {
				System.out.println("ERROR: valid directions are N,NE,E,SE,S,SW,W,NW.");
				System.out.println("Enter the direction to travel ('exit to quit) ");
				dir = kb.next().toLowerCase();
			}
		}
		
		System.out.println("Your final location is (" + x + "," + y + ")" );
	}

}
