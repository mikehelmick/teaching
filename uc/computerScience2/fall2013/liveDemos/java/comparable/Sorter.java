import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Sorter {
  
  public static void printList(List<Foo> list) {
    for (Foo foo : list) {
      System.out.print(foo + ", ");
    }
    System.out.println("");
  }

  public static void main(String args[]) {
    List<Foo> list = new ArrayList<Foo>();
    
    list.add(new Foo(22, 2));
    list.add(new Foo(10, 2));
    list.add(new Foo(15, 2));
    list.add(new Foo(12, 2));
    list.add(new Foo(22, 1));
    list.add(new Foo(10, 1));
    list.add(new Foo(15, 1));
    list.add(new Foo(12, 1));
    
    System.out.println("Natural ordering");
    Collections.sort(list);
    printList(list);
   
   
    List<Comparator<Foo>> comps = new ArrayList<Comparator<Foo>>();
    comps.add(new OrderByFirst());
    comps.add(new OrderBySecond());
    comps.add(new OrderByFirstReverse());
    
    for (Comparator<Foo> comp : comps) {
      Collections.sort(list, comp);
      System.out.println("Sorting using " + comp.getClass().getName());
      printList(list);
    }
  }
}