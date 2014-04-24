
public class ArrayExample {
  
  public static void main(String args[]) {
    int values[] = new int[10];
    for (int i = 0; i < values.length; i++) {
      values[i] = i * 2;
    }

    System.out.println("The length of values is : " + values.length);
    for (int val : values) {
      System.out.print(val + " ");
    }
    System.out.println("");
    
    System.out.println(values[values.length + 1]);
  }
  
}