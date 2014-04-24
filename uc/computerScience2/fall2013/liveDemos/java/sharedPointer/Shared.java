
public class Shared {
  
  public static void main(String[] args) {
    
    Person click = new Person("Click");
    Person clack = click;
    
    System.out.println("Click = " + click.getName() + " @ " + click);
    System.out.println("Clack = " + clack.getName() + " @ " + clack1);
  }
  
}