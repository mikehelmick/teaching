import java.util.Comparator;

public class OrderBySecond implements Comparator<Foo> {
  
  public int compare(Foo a, Foo b) {
    int result = a.getVal2() - b.getVal2();
    if (result != 0) {
      return result;
    }
    return a.getVal1() - b.getVal1();
  }
}