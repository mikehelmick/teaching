
public class OrderByFirstReverse extends OrderByFirst {
  
  @Override
  public int compare(Foo a, Foo b) {
    return -1 * super.compare(a, b);
  }
  
}