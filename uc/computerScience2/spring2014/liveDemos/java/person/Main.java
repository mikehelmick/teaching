public class Main {

  public static void main(String args[]) {

    Person p1 = new Person("Student", "123456789");
    Person p2 = new Person("Student", "123456789");

    System.out.println("p1: " + p1);
    System.out.println("p2: " + p2);

    if (p1.equals(p2)) {
      System.out.println("p1 and p2 are equal");
    }

    Example ex = new Example();
    System.out.println(ex.toString());
  }
}
