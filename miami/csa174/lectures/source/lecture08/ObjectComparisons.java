
public class ObjectComparisons {
 
  public static void main( String[] args ) {
    
    String str1 = "Miami University";
    if ( str1.equals( "Miami University" ) ) {
      System.out.println("The strings are equal.");
    }

	String name1 = "Amy";
	String name2 = "Beth";
	
	int result = name1.compareTo( name2 );
	if ( result < 0 ) {
		System.out.println( name1 + " is before " + name2 + " lexographically "); 
	} else {
		System.out.println( name1 + " is after " + name2 + " lexographically ");
	}
    
    
  }
  
}