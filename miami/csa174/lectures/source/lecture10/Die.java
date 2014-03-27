import java.util.Random;

/**
 * Represents a single die - a standard die with 6 sides
 * @author Mike Helmick - based on work in Java Foundations
 */
public class Die {
	// number of sides
	private final int MAX = 6;
	
	// current face value
	private int faceValue = 1;
	
	private Random random = null;
	
	public Die() {
		random = new Random();
	}
	
	/**
	 * Roll the dice and return the new value
	 * @return die value
	 */
	public int roll() {
		faceValue = random.nextInt(MAX) + 1;
		return faceValue;
	}
	
	/**
	 * position the die to a specific value
	 * @param value new value for the die
	 */
	public void setFaceValue( int value ) {
		faceValue = value;
	}
	
	/**
	 * Return the current face value of the die
	 */
	public int getFaceValue() {
		return faceValue;
	}
	
	public String toString() {
		return "" + faceValue;
	}
	
}



