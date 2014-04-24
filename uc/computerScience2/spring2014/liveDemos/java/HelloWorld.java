
public class HelloWorld {

  public static void main(String args[]) {
    System.out.println("Hello, world!");

    System.out.println("You passed " + args.length + " arguments");
    for (String arg : args) {
      System.out.println(arg);
    }

  }
}
