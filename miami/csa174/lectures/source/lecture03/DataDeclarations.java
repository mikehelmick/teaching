public class DataDeclarations {

	public static void main( String[] args ) { 
	
		float salesAmount = 23.95f;
		float taxRate = 0.065f;
		
	}
}

	
		// calculate taxes and new total
		float taxAmount = salesAmount * taxRate;
		float totalAmount = salesAmount + taxAmount;
		
		System.out.println("On a purchase of $" + salesAmount );
		System.out.println("The tax amount is $" + taxAmount );
		System.out.println("And the total amount is $" + totalAmount );
		
	}

}

