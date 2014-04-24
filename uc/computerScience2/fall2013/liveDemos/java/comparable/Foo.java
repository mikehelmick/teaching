import java.lang.Comparable;

/**
 * Foo objects contain two integers. They are sorted first by the first item
 * and then by the second.
 */
public class Foo implements Comparable<Foo> {
  private int val1;
  private int val2;
  
  public Foo(int val1, int val2) {
    this.val1 = val1;
    this.val2 = val2;
  }
  
  public String toString() {
    return val1 + "-" + val2;
  }
  
  public int getVal1() {
    return val1;
  }
  
  public int getVal2() {
    return val2;
  }
  
  @Override
  public int compareTo(Foo other) {
    int result = val1 - other.val1;
    if (result != 0) {
      return result;
    }
    return val2 - other.val2;
  }
}


