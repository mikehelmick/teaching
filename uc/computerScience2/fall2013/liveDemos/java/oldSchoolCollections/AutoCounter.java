
public class AutoCounter {
  
  private final int value;
  
  private static int nextValue = 0;
  
  public AutoCounter() {
    value = nextValue;
    nextValue++;
  }

  public int getValue() {
    return value;
  }

  @Override
  public String toString() {
    return super.toString() + ",value=" + value;
  }
}