import java.util.Scanner;

/**
 * Mike Helmick
 * Program that reads 
 **/
public class Dates {
 
    public static void main( String[] args ) {
        Scanner kb = new Scanner( System.in );
        
        System.out.println("Enter a date in the form month day year: ");
        String month = kb.next().toLowerCase();
        // correct casing
        month = month.substring(0,1).toUpperCase() + month.substring(1);
        // read day and year
        int day = kb.nextInt();
        int year = kb.nextInt();
        
        // calculate leap offset
        int leapAddition = 0;
        if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ) {
            leapAddition = 1;
        }
        final int maxDay = 365 + leapAddition;
        
        int previousDays = 0;
        if ( "January".equals(month) ) {
            previousDays = 0;
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else if ( "February".equals(month) ) {
            previousDays = 31; // J
			if ( day < 1 || day > 28 + leapAddition ) {
				int max = 28 + leapAddition;
				System.out.println("Invalid day entered, must be between 1 and " + max);
				System.exit(0);
			}
        } else if ( "March".equals(month) ) {
            previousDays = 31 + (28+leapAddition); // J F
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else if ( "April".equals(month) ) {
            previousDays = 31*2 + (28+leapAddition); // J F M
			if ( day < 1 || day > 30 ) {
				System.out.println("Invalid day entered, must be between 1 and 30");
				System.exit(0);
			}
        } else if ( "May".equals(month) ) {
            previousDays = 31*2 + 30 + (28+leapAddition); // J F M A
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else if ( "June".equals(month) ) {  
            previousDays = 31*3 + 30 + (28+leapAddition); // J F M A M
			if ( day < 1 || day > 30 ) {
				System.out.println("Invalid day entered, must be between 1 and 30");
				System.exit(0);
			}
        } else if ( "July".equals(month) ) {    
            previousDays = 31*3 + 30*2 + (28+leapAddition); // J F M A M J
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else if ( "August".equals(month) ) {
            previousDays = 31*4 + 30*2 + (28+leapAddition); // J F M A M J J
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else if ( "September".equals(month) ) { 
            previousDays = 31*5 + 30*2 + (28+leapAddition); // J F M A M J J A
			if ( day < 1 || day > 30 ) {
				System.out.println("Invalid day entered, must be between 1 and 30");
				System.exit(0);
			}
        } else if ( "October".equals(month) ) {    
            previousDays = 31*5 + 30*3 + (28+leapAddition); // J F M A M J J A S
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else if ( "November".equals(month) ) {    
            previousDays = 31*6 + 30*3 + (28+leapAddition); // J F M A M J J A S O
			if ( day < 1 || day > 30 ) {
				System.out.println("Invalid day entered, must be between 1 and 30");
				System.exit(0);
			}
        } else if ( "December".equals(month) ) {    
            previousDays = 31*6 + 30*4 + (28+leapAddition); // J F M A M J J A S O N
			if ( day < 1 || day > 31 ) {
				System.out.println("Invalid day entered, must be between 1 and 31");
				System.exit(0);
			}
        } else {
            System.out.println("Invalid month entered.");
            System.exit(0);
        }
        
        if ( leapAddition > 0 ) {
            System.out.println( year + " is a leap year.");
        } else {
            System.out.println( year + " is not a leap year.");
        }
        System.out.println( month + " " + day + ", " + year );
        
        int currentDay = previousDays + day;
        int daysLeft = maxDay - currentDay;
        
        System.out.println("is day #" + currentDay + " of the year.");
        System.out.println("there are " + daysLeft + " days remaining in the year.");
        
        
    }
    
}