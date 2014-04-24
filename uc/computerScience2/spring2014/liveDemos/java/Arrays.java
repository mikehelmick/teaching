import java.util.Random;

public class Arrays {

  public static void main(String args[]) {

    Random rand = new Random(System.currentTimeMillis());

    int intArray[] = new int[rand.nextInt(10) + 10];
    for (int i = 0; i < intArray.length; i++) {
      intArray[i] = rand.nextInt(100);
    }

    for (int value : intArray) {
      System.out.println(value);
    }
  }
}
