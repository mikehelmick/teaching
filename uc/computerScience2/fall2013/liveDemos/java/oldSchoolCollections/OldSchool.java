import java.util.List;
import java.util.ArrayList;

public class OldSchool {

  // For use in counter example
  static class Foo {
    // left intentionally blank
  }
  
  public static void printAutoCounters(List counters) {
    for (int i = 0; i < counters.size(); i++) {
      Object thisObj = counters.get(i);
      AutoCounter thisCounter = (AutoCounter) thisObj;
      System.out.println("i=" + i + "  ->  " + thisCounter);
    }
  }
  
  public static void main(String args[]) {
    // This now holds "Object" types, which is OK since everythign in Java derives from Object
    List myList = new ArrayList();
    for (int i = 0; i < 10; i++) {
      myList.add(new AutoCounter());
    }
    //myList.add(new Foo());

    printAutoCounters(myList);
  }
}