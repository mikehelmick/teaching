import java.util.Random;

public class Search {
	private static final Random randomG = new Random();
	
	private static int linCompare = 0;
	private static int binCompare = 0;
	
	public static int[] generateArray( int size, boolean random ) {
		int[] arr = new int[size];
		for ( int i = 0; i < arr.length; i++ ) {
			if ( random ) {
				arr[i] = randomG.nextInt(100);
			} else {
				arr[i] = i + 1;
			}
		}
		return arr;
	}
	
	public static int linearSerch( int[] array, int target ) {
		int position = -1;
		
		for( int i = 0; i < array.length && position < 0; i++ ) {
			if( array[i] == target ) {
				position = i;
			}
			
			linCompare++;
		}
		
		return position;
	}
	
	/**
	 * Perform binary search over a SORTED array
	 */
	public static int binarySearch( int[] array, int target ) {
		int first = 0;
		int last = array.length - 1;
		int mid=0;
		
		int position = -1;
		
		while( position < 0 && first <= last ) {
			mid = (first + last) / 2;
			
			if ( array[mid] == target ) {
				position = mid;
			} else {
				if ( target < array[mid] ) {
					last = mid - 1;
				} else {
					first = mid + 1;
				}
			}
			
			binCompare++;
		}
		
		return position;
	}
	 
	public static void selectionSort( int[] array ) {
		int posMin = 0;
		
		for( int i = 0; i < array.length - 1; i++ ) {
			posMin = i;
			
			for( int next = i + 1; next < array.length; next++ ) {
				if ( array[next] < array[posMin] ) {
					posMin = next;
				}
			}
			 
			// swap the item at posMin and i
			int temp = array[i];
			array[i] = array[posMin];
			array[posMin] = temp;
		}
	}
	
	public static void printArray( int[] array ) {
		for( int i : array ) {
			System.out.print(i + ", ");
		}
		System.out.println();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int[] array = generateArray( 100000, true );
		
		printArray( array );
		selectionSort( array );
		printArray( array );
		
		/*
		for( int i = 1; i < array.length; i++ ) {
			System.out.println( i + " is at position " + linearSerch( array, i ) );
			System.out.println( i + " is at position " + binarySearch( array, i ) );
		}
		
		System.out.println( "linear search loops => " + linCompare );
		System.out.println(" binary search loops => " + binCompare );
		*/
		
	}

}
