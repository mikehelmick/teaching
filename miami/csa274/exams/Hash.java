
public class Hash {
	
	public static void main( String args[] ) {
		
		String str1 = "hello";
		String str2 = "goodbye";
		String str3 = "java";
		String str4 = "ruby";
		
		int mod1 = 5;
		int mod2 = 10;
		
		print( str1 );
		print( str2 );
		print( str3 );
		print( str4 );
	}
	
	public static void print( String str ) {
		System.out.println( str + "  " + str.hashCode() + "  " +
		                    (str.hashCode()%5) + "  " +
								  (str.hashCode()%10) + "  " );
	}
	
}