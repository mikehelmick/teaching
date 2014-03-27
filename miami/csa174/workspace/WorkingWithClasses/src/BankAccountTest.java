import junit.framework.TestCase;


public class BankAccountTest extends TestCase {

	private static final String name = "John Q Customer";
	private static final double balance = 100.50;
	private static final double interestRate = 1.5;
	
	public void testGetName() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		assertEquals( name, account.getName() );
	}

	public void testGetBalance() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		assertEquals( balance, account.getBalance(), 0.00001 );
	}

	public void testDeposit() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		double balance = account.getBalance();
		
		for( double amount = 10; amount < 100; amount = amount + 10.25 ) {
			double actual = account.deposit( amount );
			balance += amount; // increase expected
			
			assertEquals( balance, actual, 0.001 );
			assertEquals( balance, account.getBalance(), 0.001 );
		}
	}
	
	public void testDepositNegative() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		double actual = account.deposit( -1.0 );
		
		assertEquals( balance, actual, 0.001 );
		assertEquals( balance, account.getBalance(), 0.001 );
	}

	public void testWithdrawal() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		double actual = account.withdrawal( 10 );
		
		assertEquals( balance - 10, actual, 0.001 );
		assertEquals( balance - 10, account.getBalance(), 0.001 );
	}
	
	public void testWithdrawl_Insufficient() {
		
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		double actual = account.withdrawal( balance + 0.01 );
		
		assertEquals( balance, actual, 0.001 );
		assertEquals( balance, account.getBalance(), 0.001 );
		
	}

	public void testGetInterestRate() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		assertEquals( interestRate, account.getInterestRate(), 0.001 );
	}

	public void testApplyInterest() {
		BankAccount account = new BankAccount( name, balance, interestRate );
		
		account.applyInterest();
		
		double expected = balance + balance * interestRate / 100;
		
		assertEquals( expected, account.getBalance(), 0.001 );
	}

}
