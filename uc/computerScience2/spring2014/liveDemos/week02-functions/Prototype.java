
public class Prototype {
  public static int my_function(double x) {
    System.out.println("my_function(double) was called");
    return x;
  }

  public static int my_function(int x, int y) {
    System.out.println("my_function(int,int) was called");
    return x + y;
  }

  public static int my_function(int x) {
    System.out.println("my_function(int) was called");
    return x;
  }

/**

int my_function(int x) {
	return x;
}

*/

/*

double my_function(int x) {
	return x;
}

*/

  public static void main(String args[]) {
    System.out.println(my_function(4));
    double i = 4.5;
    double j = 4.75;
    System.out.println(my_function(i, j));
  }
}
