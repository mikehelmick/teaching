
public class Satchel {

	private CoinBag bag1;
	private CoinBag bag2;
	
	public Satchel( int amount1, int amount2 ) {
		bag1 = new CoinBag( amount1 );
		bag2 = new CoinBag( amount2 );
	}
	
	public int getCentsInBag( int bagNumber ) {
		if (bagNumber == 1) {
			return bag1.getTotalCents();
		} else if ( bagNumber == 2 ) {
			return bag2.getTotalCents();
		} else {
			return 0;
		}
	}
	
	public int getTotalCents() {
		return bag1.getTotalCents() + bag2.getTotalCents();
	}
	
	public double getDollarsInBag( int bagNumber ) {
		if (bagNumber == 1) {
			return bag1.getDollarAmount();
		} else if ( bagNumber == 2 ) {
			return bag2.getDollarAmount();
		} else {
			return 0.0;
		}
	}
	
	public double getTotalDollars() {
		return bag1.getDollarAmount() + bag2.getDollarAmount();
	}
	
	public boolean makePurchase( double dollars ) {
		return makePurchase( (int) (dollars * 100) );
	}
	
	public boolean makePurchase( int cents ) {
		if ( cents <= getTotalCents() ) {
			// we can (probably) make this work
			int quarters1 = 0, quarters2 = 0;
			int dimes1 = 0, dimes2 = 0;
			int nickels1 = 0, nickels2 = 0;
			int pennies1 = 0, pennies2 = 0;
			
			while( cents >= 25 && bag1.getQuarters() - quarters1 > 0 ) {
				cents -= 25;
				quarters1++;
			}
			while( cents >= 25 && bag2.getQuarters() - quarters2 > 0 ) {
				cents -= 25;
				quarters2++;
			}
			
			while( cents >= 10 && bag1.getDimes() - dimes1 > 0 ) {
				cents -= 10;
				dimes1++;
			}
			while( cents >= 10 && bag2.getDimes() - dimes2 > 0 ) {
				cents -= 10;
				dimes2++;
			}
			
			while( cents >= 5 && bag1.getNickels() - nickels1 > 0 ) {
				cents -= 5;
				nickels1++;
			}
			while( cents >= 5 && bag2.getNickels() - nickels2 > 0 ) {
				cents -= 5;
				nickels2++;
			}
			
			while( cents >= 1 && bag1.getPennies() - pennies1 > 0 ) {
				cents -= 1;
				pennies1++;
			}
			while( cents >= 1 && bag2.getPennies() - pennies2 > 0 ) {
				cents -= 1;
				pennies2++;
			}
			
			if ( cents == 0 ) {
				bag1.setQuarters( bag1.getQuarters() - quarters1 );
				bag1.setDimes( bag1.getDimes() - dimes1 );
				bag1.setNickels( bag1.getNickels() - nickels1 );
				bag1.setPennies( bag1.getPennies() - pennies1 );
				
				bag2.setQuarters( bag2.getQuarters() - quarters2 );
				bag2.setDimes( bag2.getDimes() - dimes2 );
				bag2.setNickels( bag2.getNickels() - nickels2 );
				bag2.setPennies( bag2.getPennies() - pennies2 );
				
				return true;	
			}
		}
		// not able to complete purchase
		return false;
	}
	
	public String toString() {
		return String.format( "Bag1 $%6.2f Bag2 $%6.2f : Total=$%6.2f", bag1.getDollarAmount(), bag2.getDollarAmount(), this.getTotalDollars() );
	}
	
}
