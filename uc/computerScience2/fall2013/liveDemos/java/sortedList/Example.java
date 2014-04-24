
public class Example {
  
  public static void main(String args[]) {
    
    SortedList<String> sl = SortedList.of();
    sl.add("One");
    sl.add("Two");
    sl.add("Three");
    sl.add("Four");
    sl.add("Five");
    sl.add("Six");
    
    System.out.println("Sorted list size: " + sl.size());
    for (String item : sl) {
      System.out.println(item);
    }
    
    
    SortedList<Integer> sl1 = SortedList.of();
    for (int i = 8; i > 0; i--) {
      sl1.add(i);
      sl1.add(i * 2);
      sl1.add(i / 2);
    }
    System.out.println("Sorted list size: " + sl1.size());
    for (Integer item : sl1) {
      System.out.println(item);
    }
  }
}