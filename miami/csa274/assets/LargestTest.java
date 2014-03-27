import junit.framework.*;

public class LargestTest extends TestCase {
	
	public LargestTest(String name) {
		super( name );
	}
	
	public void testOrder() {
		assertEquals( 5, Largest.largest( new int[] {1, 3, 5} ) );
	}
	
}

