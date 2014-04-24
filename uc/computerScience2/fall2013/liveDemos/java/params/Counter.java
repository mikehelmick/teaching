import java.util.List;
import java.util.ArrayList;

/**
 * A simple counter class, moved forward each time "tick" is called.
 */ 
public class Counter {
  
  // Static list of ALL counters ever created
  private static List<Counter> ALL_COUNTERS = new ArrayList<Counter>();

  private String name;
  private int count;

  public static List<Counter> getAllCounters() {
    return ALL_COUNTERS;
  }

  public Counter(String name) {
    this.name = name;
    this.count = 0;
    ALL_COUNTERS.add(this);
  }

  public Counter(Counter other) {
    this.name = "COPY:" + other.name;
    this.count = other.count;
    ALL_COUNTERS.add(this);
  }

  public int getCount() {
    return count;
  }

  public void tick() {
    count++;
    System.out.println("Tick! " + this);
  }

  public String toString() {
    return name + ":" + count;
  }
}