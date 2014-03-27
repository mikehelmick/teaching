
/**
 * Represents a simple gradebook as 2d array
 */
public final class Gradebook {
 
	private double[][] grades;

    public Gradebook(int numStudents, int numTests ) {
        grades = new double[numStudents][numTests];
    }

	public void setGrade( int student, int test, double score ) {
		grades[student][test] = score;
	}
	
	public double getGrade( int student, int test ) {
		return grades[student][test];
	}

	public double averageForStudent( int student ) {
		return average( grades[student] );
	}
	
	public double averageForTest( int test ) {
		double[] scores = new double[grades.length];
		
		for( int i = 0; i < grades.length; i++ ) {
			scores[i] = grades[i][test];
		}
		
		return average( scores );
	}
	
	public double averageFinalScore() {
		double[] scores = new double[grades.length];
		
		for( int i = 0; i < grades.length; i++ ) {
			scores[i] = averageForStudent( i );
		}
		
		return average( scores );
	}
	
	private static double average( double[] scores ) {
		double sum = 0;
		for( double score : scores ) {
			sum += score;
		}
		return sum / scores.length;
	}

}