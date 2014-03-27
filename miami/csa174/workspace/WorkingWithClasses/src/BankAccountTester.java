
public class BankAccountTester {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		String accountName = "Bank Customer";
		double initialBalance = 50.0;
		
		BankAccount account = new BankAccount( accountName, initialBalance, 0.9 );
		
		System.out.println( accountName + " = " + account.getName() );
		System.out.println( initialBalance + " = " + account.getBalance() );
		
		double balance = account.deposit( 20.0 );
		System.out.println( 70.0 + " = " + balance );
		
		balance = account.deposit( -20 );
		System.out.println( 70.0 + " = " + balance );
		
		System.out.println( 70.0 + " = " + account.getBalance() );
		
		// withdrawal tests
		balance = account.withdrawal( 20.0 );
		System.out.println( 50.0 + " = " + balance );
		
		balance = account.withdrawal( 500 );
		System.out.println( 50.0 + " = " + balance );
		System.out.println( 50.0 + " = " + account.getBalance() );

		// test getInterestRate()
		System.out.println( 0.9 + " = " + account.getInterestRate() );
		
		// test apply interest
		double targetBalance = account.getBalance() + account.getBalance() * 0.009;
		account.applyInterest();
		balance = account.getBalance();
		
		System.out.println( targetBalance + " = " + balance );
		
		System.out.println( account );
		System.out.println( account.toString() );
	}
	

}
