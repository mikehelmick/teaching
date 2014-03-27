
/**
 * A class that represents a coin bag
 * @author mhelmick
 *
 */
public class CoinBag {

	private int quarters = 0;
	private int dimes = 0;
	private int nickels = 0;
	private int pennies = 0;
	
	/**
	 * Create a coin bag that holds X pennies
	 * @param amount
	 */
	public CoinBag( int amount ) {
		while( amount >= 25 ) {
			quarters++;
			amount -= 25;
		}
		while( amount >= 10 ) {
			dimes++;
			amount -= 10;
		}
		while( amount >= 5 ) {
			nickels++;
			amount -= 5;
		}
		pennies = amount;
	}
	
	public CoinBag( int quarters, int dimes, int nickles, int pennies ) {
		this.quarters = quarters;
		this.dimes = dimes;
		this.nickels = nickles;
		this.pennies = pennies;
	}

	public int getQuarters() {
		return quarters;
	}

	public void setQuarters(int quarters) {
		this.quarters = quarters;
	}

	public int getDimes() {
		return dimes;
	}

	public void setDimes(int dimes) {
		this.dimes = dimes;
	}

	public int getNickels() {
		return nickels;
	}

	public void setNickels(int nickels) {
		this.nickels = nickels;
	}

	public int getPennies() {
		return pennies;
	}

	public void setPennies(int pennies) {
		this.pennies = pennies;
	}
	
	public int getTotalCents() {
		return quarters * 25 + dimes * 10 + nickels * 5 + pennies;
	}
	
	public double getDollarAmount() {
		return getTotalCents() / 100.0;
	}
	
	public String toString() {
		return String.format( "Coin bag holds $%.2f", getDollarAmount() ); 
	}
}
