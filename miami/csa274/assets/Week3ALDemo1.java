import java.util.List;
import java.util.ArrayList;

public class Week3ALDemo1 {

	public static void main( String[] args ) {
		
		List<String> myList = new ArrayList<String>();
	
		myList.add("Homestar Runner");
		myList.add("Strong Bad");
		myList.add("The Cheat");
		
		myList.remove( 1 );
		
		// result of the .equals method!!!!
		int idx = myList.indexOf("The Cheat");
	
		for( String str : myList ) {
			System.out.println( str );
		}
	
	}

}

