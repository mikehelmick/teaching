/**
 * Class that represents a person who is walking on a grid and can go
 * 8 directions (N,S,E,W,NE,NW,SE,SW) in integer steps
 * @author Mike Helmick
 */
public class Person {

	private int xPos = 0;
	private int yPos = 0;
	private int steps = 0;
	
	// directions
	public static final double NE = Math.PI / 4.0;
	public static final double SE = NE + Math.PI / 2.0;
	public static final double SW = SE + Math.PI / 2.0;
	public static final double NW = SW + Math.PI / 2.0;
	
	public Person() {
		// nothing to do
	}

	public int getSteps() {
		return steps;
	}

	public int getXPos() {
		return xPos;
	}

	public int getYPos() {
		return yPos;
	}
	
	/**
	 * Moves the person the requested number of steps, in the sepcified direction
	 * 
	 * @param direction - one of N,S,E,W,NE,NW,SE,SW
	 * @param steps - positive number
	 * @return true if the person was moved, false if parameters are invalid
	 */
	public boolean move( String direction, int steps ) {
		if ( !(validDirection(direction) && validSteps(steps) ) ) {
			return false;
		}
		// needed to accept any direction
		direction = direction.toLowerCase();
		
		this.steps += steps;
		
		if ( direction.equals("n") ) {
			yPos += steps;
		} else if ( direction.equals("s") ) {
			yPos -= steps;
		} else if ( direction.equals("e") ) {
			xPos += steps;
		} else if ( direction.equals("w") ) {
			xPos -= steps;
		} else if ( direction.equals("ne") ) {
			int xc = (int) Math.ceil( steps * Math.cos( NE ) );
			int yc = (int) Math.ceil( steps * Math.sin( NE ) );
			xPos += xc;
			yPos += yc;
			
		} else if ( direction.equals("nw") ) {
			int xc = (int) Math.ceil( steps * Math.cos( NW ) );
			int yc = (int) Math.ceil( steps * Math.sin( NW ) );
			xPos += xc;
			yPos += yc;
			
		} else if ( direction.equals("se") ) {
			int xc = (int) Math.ceil( steps * Math.cos( SE ) );
			int yc = (int) Math.ceil( steps * Math.sin( SE ) );
			xPos += xc;
			yPos += yc;
			
		} else if ( direction.equals("sw") ) {
			int xc = (int) Math.ceil( steps * Math.cos( SW) );
			int yc = (int) Math.ceil( steps * Math.sin( SW ) );
			xPos += xc;
			yPos += yc;
			
		}
		
		return true;
	}
	
	/**
	 * Returns true if the direction is valid
	 * @param direction direction to check
	 * @return true if valid, false if not
	 */
	public boolean validDirection( final String direction ) {
		final String dirLower = direction.toLowerCase();
		return dirLower.equals("n")  || dirLower.equals("s")  ||
		       dirLower.equals("e")  || dirLower.equals("w")  ||
		   	   dirLower.equals("ne") || dirLower.equals("nw") ||
		   	   dirLower.equals("se") || dirLower.equals("sw");
	}
	
	/**
	 * Returns true if the number of steps is valid (>= 1)
	 * @param steps number of steps to check
	 * @return true if the number of steps is valid, false otherwise
	 */
	public boolean validSteps( final int steps ) {
		return steps >= 1;
	}
	
	public String toString() {
		StringBuilder build = new StringBuilder();
		build.append( "You are now at (" );
		build.append( xPos );
		build.append( "," );
		build.append( yPos );
		build.append( ")\n" );
		build.append( "Steps Taken (" );
		build.append( steps );
		build.append( "): " );
		int intervals = (int) Math.ceil( steps / 10.0 );
		for( int i = 0; i < intervals; i++ ) {
			build.append("*");
		}
		
		return build.toString();
	}
	
}
