/**
 * Custom String class - very handy
 * @author Mike Helmick
 */
public class MyString {
	
	private final char[] string;
	
	public MyString( String str ) {
		string = str.toCharArray();
	}
	
	public MyString() {
		string = new char[0];
	}
	 
	public MyString( char[] characters ) {
		string = new char[characters.length];
		for( int i = 0; i < string.length; i++ ) {
			string[i] = characters[i];
		}
	}
	
	public char charAt( int index ) {
		if ( index < 0 || index >= string.length ) {
			throw new IndexOutOfBoundsException();
		}
		return string[index];
	}
	
	public MyString concat( MyString other ) {
		char[] arr = new char[string.length + other.string.length];
		for( int i = 0; i < string.length; i++ ) {
			arr[i] = string[i];
		}
		for( int i = 0; i < other.string.length; i++ ) {
			arr[i+string.length] = other.string[i];
		}
		
		return new MyString( arr );
	}
	
	public int length() {
		return string.length;
	}
	
	public boolean equals( MyString other ) {
		if ( string.length != other.string.length ) {
			return false;
		}
		
		boolean result = true;
		for( int i = 0; i < string.length && result; i++ ) {
			result = string[i] == other.string[i];
		}
		
		return result;
	}
	
	public int indexOf( char c ) {
		int idx = -1;
		for( int i = 0; i < string.length && idx < 0; i++ ) {
			if ( string[i] == c ) {
				idx = i;
			}
		}
		return idx;
	}
	
	public int lastIndexOf( char c ) {
		int idx = -1;
		for( int i = string.length - 1; i >= 0 && idx < 0; i-- ) {
			if ( string[i] == c ) {
				idx = i;
			}
		}
		return idx;
	}
	
	public char[] toCharArray() {
		char[] rtn = new char[string.length];
		for( int i = 0; i < rtn.length; i++ ) {
			rtn[i] = string[i];
		}
		return rtn;
	}
	
	public MyString toLowerCase() {
		char[] rtn = new char[string.length];
		for( int i = 0; i < rtn.length; i++ ) {
			rtn[i] = Character.toLowerCase( string[i] );
		}
		return new MyString( rtn );	
	}
	
	public MyString toUpperCase() {
		char[] rtn = new char[string.length];
		for( int i = 0; i < rtn.length; i++ ) {
			rtn[i] = Character.toUpperCase( string[i] );
		}
		return new MyString( rtn );	
	}
	
	public MyString substring( int start ) {
		if ( start < 0 || start >= string.length ) {
			throw new IndexOutOfBoundsException();
		}
		char[] arr = new char[string.length - start];
		for( int i = 0; i < arr.length; i++ ) {
			arr[i] = string[i + start];
		}
		return new MyString( arr );
	}
	
	public MyString substring( int start, int end ) {
		if ( start < 0 || start >= string.length || end < 0 || end >= string.length || end < start ) {
			throw new IndexOutOfBoundsException();
		}
		char[] arr = new char[end-start];
		for( int i = 0; i < end-start; i++ ) {
			arr[i] = string[i + start];
		}
		return new MyString( arr );
	}
	
	public String toString() {
		return new String( string );
	}
	
	public boolean sameCharacters( MyString other ) {
		// for each character in this string
		for( int i = 0; i < string.length; i++ ) {
			if ( other.indexOf( string[i] ) < 0 ) {
				return false;
			}
		}
		return true;
	}
	
}