
public class CounterExample {

  public CounterExample() {

  }

  public int get5() {
    return 5;
  }

  public static void main(String[] args) {

    CounterExample ex = new CounterExample();
    ex = null;

    ex.get5();
  }

}
