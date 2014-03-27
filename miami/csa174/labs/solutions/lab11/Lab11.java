import java.util.Scanner;
import java.util.Arrays;

public class Lab11 {
	
	public static void main( String[] args ) {
		Scanner scanner = new Scanner( System.in );
		
		double[] scores = getScores( scanner );
		System.out.println("There are " + scores.length + " test scores.");
		System.out.printf("The minimum score is: %.2f%n", minimum(scores) );
		System.out.printf("The maximum score is: %.2f%n", maximum(scores) );
		System.out.printf("   The mean score is: %.2f%n", mean(scores) );
		System.out.printf(" The median score is: %.2f%n", median(scores) );
	
	}

	public static double minimum( double[] arr ) {
		double min = arr[0];
		for( int i = 1; i < arr.length; i++ ) {
			if ( arr[i] < min ) {
				min = arr[i];
			}
		}
		return min;
	}
	
	public static double maximum( double[] arr ) {
		double max = arr[0];
		for( int i = 1; i < arr.length; i++ ) {
			if ( arr[i] > max ) {
				max = arr[i];
			}
		}
		return max;
	}
	
	public static double mean( double[] arr ) {
		double sum = 0;
		for( double e : arr ) {
			sum += e;
		}
		return sum/arr.length;
	}
	
	public static double median( double[] arr ) {
		Arrays.sort( arr );
		int middle = arr.length/2;
		return arr[middle];
	}

	public static double[] getScores( Scanner kb ) {
		System.out.println("How many test scores?");
		int num = kb.nextInt();
		
		double[] scores = new double[num];
		for( int i = 0; i < scores.length; i++ ) {
			System.out.print("Enter score " + (i+1) + ": " );
			scores[i] = kb.nextDouble();
		}
		
		return scores;
	}
	
}