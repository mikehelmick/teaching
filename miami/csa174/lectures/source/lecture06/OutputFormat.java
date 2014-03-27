import java.util.Scanner;

/**
 * Mike Helmick
 * Example that shows how to use printf
 */
public class OutputFormat {
   
    public static void main( String[] args ) {
        // scanner - input form the user
        Scanner keyboard = new Scanner( System.in );
        
        
        System.out.print("How much was your purchase? ");
        double purchase = keyboard.nextDouble();
        
        System.out.print("What is the tax rate? " );
        double taxRate = keyboard.nextDouble();
        
        // calculate total amount
        double taxAmount = purchase * (taxRate / 100);
        double totalAmount = purchase + taxAmount;
        
        // format the output for the user
        System.out.printf("Your purchase was for $%12.2f\n", purchase );
        System.out.printf("           tax amount $%12.2f\n", taxAmount );
        System.out.println("-----------------------------------------");
        System.out.printf("    Total Amount Paid $%12.2f\n", totalAmount );
        
    }
    
}