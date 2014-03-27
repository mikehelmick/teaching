import java.util.Scanner;

/**
 * Mike Helmick
 * A program to read in information from the user and print statistics 
 */ 
public class Program4 {
	
	public static void main( String[] args ) {
		Scanner keyboard = new Scanner( System.in );
		
		// customer name
		System.out.print("What is your full name? ");
		String fullName = keyboard.nextLine().toLowerCase().trim();
		int index = fullName.indexOf(" ");
		String firstName = fullName.substring(0,1).toUpperCase() + fullName.substring(1,index);
		String lastName  = fullName.substring(index+1,index+2).toUpperCase() + fullName.substring(index+2);
		String name = lastName + ", " + firstName;
		
		// phone number
		System.out.print("What is your 10 digit phone number, with no formatting? ");
		String phoneIn = keyboard.nextLine();
		String phone = "(" + phoneIn.substring(0,3) + ") " + 
		               phoneIn.substring(3,6) + "-" +
					   phoneIn.substring(6,10);
		
		// read in product 1
		System.out.print("What is the name of first product that you bought? ");
		String productOne = keyboard.next();
		
		System.out.print("What is the cost of one " + productOne + " ? ");
		double costOne = keyboard.nextDouble();
		
		System.out.print("How many of " + productOne + " did you buy? ");
		int quantityOne = keyboard.nextInt();
		
		// read in product 2
		System.out.print("What is the name of second product that you bought? ");
		String productTwo = keyboard.next();
		
		System.out.print("What is the cost of one " + productTwo + " ? ");
		double costTwo = keyboard.nextDouble();
		
		System.out.print("How many of " + productTwo + " did you buy? ");
		int quantityTwo = keyboard.nextInt();
		
		// sales tax
		System.out.print("What is the sales tax percent? ");
		double taxRate = keyboard.nextDouble();
		
		// prepare invoice
		System.out.println("----------");
		System.out.printf("%-50s%15s%n", name, phone );
		System.out.printf("   Product Name                   Price      Quantity Total%n");
		double totalOne = costOne * quantityOne;
		System.out.printf("1) %-30s $%9.2f %8d $%10.2f%n", productOne, costOne, quantityOne, totalOne );
		double totalTwo = costTwo * quantityTwo;
		System.out.printf("2) %-30s $%9.2f %8d $%10.2f%n", productTwo, costTwo, quantityTwo, totalTwo );		
		System.out.println("-----------------------------------------------------------------");
		
		double subTotal = totalOne + totalTwo;
		System.out.printf("%54s$%10.2f%n", "Subtotal ", subTotal );
		double tax = subTotal * (taxRate / 100);
		System.out.printf("%54s$%10.2f%n", "Sales Tax ", tax );
		
		System.out.println("-----------------------------------------------------------------");
		double total = subTotal + tax;
		System.out.printf("%54s$%10.2f%n", "Total Due ", total );
		
	}
	
}