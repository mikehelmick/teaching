import java.util.List;
import java.util.ArrayList;

public class NewSchool {
  static class Foo {
    // left intentionally blank
  }
  
  public static void printAutoCounters(List<AutoCounter> counters) {
    for (int i = 0; i < counters.size(); i++) {
      AutoCounter thisCounter = counters.get(i);
      System.out.println("i=" + i + "  ->  " + thisCounter);
    }
    
    // Better yet, if you don't need the index, the enhanced for loop
    for (AutoCounter thisCounter : counters) {
      System.out.println(thisCounter);
    }
  }
  
  public static void main(String args[]) {
    // This now holds "Object" types, which is OK since everythign in Java derives from Object
    List<AutoCounter> myList = new ArrayList<AutoCounter>();
    for (int i = 0; i < 10; i++) {
      myList.add(new AutoCounter());
    }

    printAutoCounters(myList);
  }
}