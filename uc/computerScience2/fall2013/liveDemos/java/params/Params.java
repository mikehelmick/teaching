
public class Params {
  
  public static void tickCounter1(Counter counter) {
    counter.tick();
    counter = new Counter(counter);
    counter.tick();
  }
  
  public static void tickCounter2(Counter counter) {
    counter = new Counter("tickCounter2");
    counter.tick();
  }
  
  public static void main(String args[]) {
    Counter myCounter = new Counter("MAIN");
    myCounter.tick();
    tickCounter1(myCounter);
    myCounter.tick();
    tickCounter2(myCounter);
    
    System.out.println("Final state for all counters:");
    for (Counter counter : Counter.getAllCounters()) {
      System.out.println(counter);
    }
  }  
}
