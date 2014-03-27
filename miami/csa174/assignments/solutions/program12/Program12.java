import java.util.Scanner;

/**
 * Main file for Program 12
 * SUBMIT THIS FILE WITH YOUR IMPLEMENTATINO OF THE MyString class
 * @author Mike Helmick  
 */
public class Program12 {
	

	
	
	public static void main( String[] args ) {
		Scanner kb = new Scanner( System.in );
		System.out.println("MyString tester");
		
		System.out.println("Enter line 1: ");
		String referenceA = kb.nextLine();
		MyString string1 = new MyString( referenceA.toCharArray() );
		
		System.out.println("Enter line 2: ");
		String referenceB = kb.nextLine();
		MyString string2 = new MyString( referenceB.toCharArray() );
		
		System.out.println("Enter line 3: ");
		String referenceC = kb.nextLine();
		MyString string3 = new MyString( referenceC.toCharArray() );
		
		printStats( string1, referenceA, string2, referenceB, string3, referenceC );
		printStats( string2, referenceB, string1, referenceA, string3, referenceC );
		printStats( string3, referenceC, string1, referenceA, string2, referenceB );
	}
	
	public static void printStats( MyString a, String referenceA,
	                               MyString b, String referenceB, 
	                               MyString c, String referenceC ) {
		
		System.out.println("For the MyString '" + a.toString() + "':");
		System.out.println("**There are " + a.length() + " characters");
		System.out.print("**");
		for( int i = 0; i < a.length(); i++ ) {
			System.out.print( a.charAt(i) + " " );
		}
		System.out.println("**");
		
		System.out.println("Testing the .equals method.");
		System.out.print("** Test 1...");
		if ( a.equals(a) && referenceA.equals(referenceA)) {
			System.out.println("passed!");
		} else {
			System.out.println("FAILED");
		}
		System.out.print("** Test 2...");
		if ( !a.equals(b) && !referenceA.equals(referenceB) ) {
			System.out.println("passed!");
		} else {
			System.out.println("FAILED");
		}
		
		System.out.print("Testing indexOf() method:");
		boolean passed = true;
		for( int i = 0; i < referenceA.length(); i++ ) {
			if ( a.indexOf(referenceA.charAt(i)) == referenceA.indexOf(referenceA.charAt(i))) {
				System.out.print(".");
			} else {
				System.out.print("!");
				passed = false;
			}
		}
		if ( passed ) { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
		
		System.out.print("Testing lastIndexOf() method:");
		passed = true;
		for( int i = 0; i < referenceA.length(); i++ ) {
			if ( a.lastIndexOf(referenceA.charAt(i)) == referenceA.lastIndexOf(referenceA.charAt(i))) {
				System.out.print(".");
			} else {
				System.out.print("!");
				passed = false;
			}
		}
		if ( passed ) { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
		
		System.out.println("Testing toCharArray: ");
		char[] msArray = a.toCharArray();
		char[] refArray = referenceA.toCharArray();
		passed = msArray.length == refArray.length;
		for( int i = 0; i < referenceA.length(); i++ ) {
			if ( msArray[i] == refArray[i] ) {
				System.out.print(".");
			} else {
				System.out.print("!");
				passed = false;
			}
		}
		if ( passed ) { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
		
		System.out.print("Testing toUpperCase(): ");
		MyString upperA = a.toUpperCase();
		MyString upperRef = new MyString( referenceA.toUpperCase().toCharArray() );
		if ( upperA.equals( upperRef ) )  { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
		
		System.out.print("Testing toLowerCase(): ");
		String lowerA = new String( a.toLowerCase().toCharArray() );
		String lowerRef = referenceA.toLowerCase();
		if ( lowerA.equals( lowerRef ) )  { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
		
		System.out.print("Testing substring(s):");
		passed = true;
		for( int i = 0; i < referenceA.length(); i++ ) {
			String subA = a.substring(i).toString();
			String subRef = referenceA.substring(i);
			
			if ( subA.equals(subRef) ) {
				System.out.print(".");
			} else {
				System.out.print("!");
				passed = false;
			}
		}
		if ( passed ) { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
		
		System.out.print("Testing substring(s,e):");
		passed = true;
		for( int i = 0; i < referenceA.length() - 1; i++ ) {
			for( int j = i + 1; j < referenceA.length(); j++ ) {
				String subA = a.substring(i,j).toString();
				String subRef = referenceA.substring(i,j);

				if ( subA.equals(subRef) ) {
					System.out.print(".");
				} else {
					System.out.print("!");
					passed = false;
				}
			}
		}
		if ( passed ) { 
			System.out.println("passed!");
		} else {
			System.out.println("FAILED!");
		}
	
		
		System.out.println("Invoking sameCharacters");
		System.out.println( "'" + a + "' same as '" + b + "' ==> " + a.sameCharacters(b) );
		System.out.println( "'" + a + "' same as '" + c + "' ==> " + a.sameCharacters(c) );
	
		System.out.print("Testing toCharArray...");
		char arr[] = a.toCharArray();
		for( int i = 0; i < arr.length; i++ ) {
			arr[i] = (char)(arr[i]-1);
		}
		if ( a.equals( new MyString(arr) ) ) {
			System.out.println("FAILED!");
		} else {
			System.out.println("passed!");
		}
	
		
		for( int i = 0; i < 50; i++ ) {
			System.out.print("*");
		}
		System.out.println("*");
	}
	
}