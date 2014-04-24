public class Example {
  
  public static void main(String args[]) {
    Topping pepperoni = new Topping("pepperoni", false);
    Topping cheese = new Topping("cheese");
    Topping extra_cheese = new Topping("extra cheese", true);

    Pizza pizza = new Pizza();
    pizza.addTopping(pepperoni);
    pizza.addTopping(extra_cheese);

    System.out.println("My pizza has " + pizza.getToppingsCount() + " toppings.");
    for (Topping topping : pizza.getToppings()) {
      System.out.println("  + " + topping.getName());
    }
    System.out.println("The final price is $" + pizza.getPrice());
  }
}
