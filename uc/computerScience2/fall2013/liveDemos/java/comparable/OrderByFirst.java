import java.util.Comparator;

public class OrderByFirst implements Comparator<Foo> {
  
  public int compare(Foo a, Foo b) {
    return a.compareTo(b);
  }
}