import java.util.Scanner;

/**
 * Solution for lab 12 - main class for gradebook program
 * @author Mike Helmick
 */
public final class Main {
  
	public static void main( String[] args ) {
		Scanner kb = new Scanner( System.in );
		
		System.out.print("How many students? ");
		int students = kb.nextInt();
		System.out.print("How many tests? ");
		int tests = kb.nextInt();
		
		Gradebook grades = new Gradebook( students, tests );
		
		for( int i = 0; i < students; i++ ) {
			System.out.println("Enter " + tests + " test scores for student number " + (i+1) + "." );
			for( int j = 0; j < tests; j++ ) {
				double score = kb.nextDouble();
				grades.setGrade( i, j, score );
			}
			System.out.println("----------");
		}
		
		for( int i = 0; i < 40; i++ ) {
			System.out.print("*");
		}
		System.out.println("");
		
		// output
		System.out.println("Average test scores:");
		for( int i = 0; i < tests; i++ ) {
			System.out.printf("Test #%d = %.2f%n", i+1, grades.averageForTest(i) );
		}
		
		System.out.println("Average for students:");
		for( int i = 0; i < students; i++ ) {
			System.out.printf("Student #%d = %.2f%n", i+1, grades.averageForStudent(i) );
		}
		
		System.out.print("Overall average for the class: ");
		System.out.printf("%.2f%n", grades.averageFinalScore() );
		
	}

}
