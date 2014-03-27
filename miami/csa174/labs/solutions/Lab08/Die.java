import java.util.Random;

/**
 * Die class for lab 08
 * @author mhelmick
 */
public class Die {
	
	private final int MAX = 6;
	
	private int faceValue = 1;
	
	private int oneRoll = 0;
	private int twoRoll = 0;
	private int threeRoll = 0;
	private int fourRoll = 0;
	private int fiveRoll = 0;
	private int sixRoll = 0;
	
	private static final Random random = new Random();
	
	public Die() {
	}
	
	/**
	 * Roll the dice and return the new value
	 * @return
	 */
	public int roll() {
		faceValue = random.nextInt(MAX) + 1;
		increaseRoll();
		return faceValue;
	}
	
	public int totalRolls() {
		return oneRoll + twoRoll + threeRoll +
		       fourRoll + fiveRoll + sixRoll;
	}
	
	public int getFaceValue() {
		return faceValue;
	}
	
	public boolean setFaceValue( int value ) {
		if ( value < 1 || value > 6 ) {
			return false;
		}
		
		faceValue = value;
		return true;
	}
	
	public int rollsByValue( int value ) {
		int rtn = -1;
		switch( value ) {
		  case 1: rtn = oneRoll; break;
		  case 2: rtn = twoRoll; break;
		  case 3: rtn = threeRoll; break;
		  case 4: rtn = fourRoll; break;
		  case 5: rtn = fiveRoll; break;
		  case 6: rtn = sixRoll; break;		
		}
		return rtn;
	}
	
	private void increaseRoll() {
		switch( faceValue ) {
		  case 1: oneRoll++; break;
		  case 2: twoRoll++; break;
		  case 3: threeRoll++; break;
		  case 4: fourRoll++; break;
		  case 5: fiveRoll++; break;
		  case 6: sixRoll++; break;
		}
	}
	
}
