
/**
 * This class represents a single bank account
 * that generates interest
 * @author Mike Helmick
 */
public class BankAccount {

	// Instance Variables
	private String name = "";
	private double balance = 0.0;
	private double interestRate = 0.0;
	
	// Constructor(s)
	public BankAccount( String name, double balance, double interestRate ) {
		this.name = name;
		this.balance = balance;
		this.interestRate = interestRate;
	}
	
	// methods
	/**
	 * Returns the name of the account holder
	 */
	public String getName() {
		return name;
	}

	/**
	 * Returns the account balance
	 * @return
	 */
	public double getBalance() {
		return balance;
	}
	
	/**
	 * Make a deposit to the account if the deposit amount is > 0
	 * Otherwise the balance remains unchanged
	 * @param depositAmount a positivie number
	 * @return the account balance
	 */
	public double deposit( double depositAmount ) {
		if ( depositAmount > 0 ) {
			balance += depositAmount;
		}
		return balance;
	}
	
	/**
	 * Withdrawal amount from the account if there is enough money in the account
	 * Returns the new balance
	 * @param amount amount to deduct, <= getBalance()
	 * @return new balance 
	 */
	public double withdrawal( double amount ) {
		if ( amount <= balance ) {
			balance -= amount;
		}
		return balance;
	}
	
	/**
	 * 
	 * @return the current interest rate of the account
	 */
	public double getInterestRate() {
		return interestRate;
	}
	
	public void applyInterest() {
		if ( interestRate > 0 ) {
			balance = balance + balance * interestRate / 100.0;
		}
	}
	
	public String toString() {
		return String.format("%s Balance=$%.2f, APR=%.1f%%", name, balance, interestRate );
	}
	
}
